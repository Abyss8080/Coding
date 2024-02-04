###########################################
#准备分析的内容写入txt文件，命名为“example.txt”#
##########################################

Dict = {"main": 1, "int": 2, "char": 3, "if": 4, "else": 5, "while": 6, "return": 7,
        "INT": 20, "STRING": 40, "id": 80,
        "+": 21, "-": 22, "*": 23, "/": 24,
        "==": 25, "!=": 26, ">=": 27, "<=": 28, ">": 29, "<": 30, "=": 31,
        "(": 41, ")": 42, "{": 43, "}": 44, ",": 45, ";": 46, "\"": 47, "#": 48}
INT_table = []
STRING_table = []
ID_table=[]
final_filename = "example_lexical_result.txt"
table_filename = "example_table.txt"
line = 1

# 报错
def Print_Error(num, i):
    with open(final_filename, "a") as f:
        print("\nError!", file=f)
        match num:
            case 1:
                print("Reason:integer constants Error!", file=f)
            case 2:
                print("Reason:operator Error!", file=f)
            case 3:
                print("Reason:No such character in dictionary!", file=f)
            case 4:
                print("Reason:string not ends with \" !", file=f)
            case 5:
                print("Reason:identifier Error!", file=f)
            case 6:
                print("Reason:file not ends with # !", file=f)
            case _:
                print("Reason:Unknown error!", file=f)
        print("Error line:", line, file=f)
        print(file=f)
        return i + 1
    

def Op_tablewrite(value, element):
    global INT_table
    global STRING_table
    global ID_table
    if value == 20:
        table = INT_table
    elif value ==40:
        table = STRING_table
    else:
        table=ID_table
    num = table.count(element)
    if num == 0:
        table.append(element)
        tableindex = table.index(element)
    else:
        tableindex = table.index(element)
    return tableindex


# 该字符ch是不是字母
def isCharacter(ch):
    value = ord(ch)
    return value >= 97 and value <= 122 or value >= 65 and value <= 90


# 该字符ch是不是数字
def isNumber(ch):
    return ch >= '0' and ch <= '9'


# 该字符是不是+-*/
def isOperator(ch):
    value = Dict[ch]
    return value >= 21 and value <= 24


# 该字符是不是=！<>
def isLS(ch):
    return ch == "=" or ch == "!" or ch == "<" or ch == ">"


# 该字符是不是界限符{}(),;#
def isBound(ch):
    value = Dict[ch]
    return value >= 41 and value <= 48


# 该字符ch是不是界限符或者运算符
def isSign(ch):
    if ch not in Dict.keys():
        return False
    else:
        return isOperator(ch) or isLS(ch) or isBound(ch)


# 读出关键字或者标识符,返回位置
def Read_Key_or_ID(content, i):
    with open(final_filename, "a") as f:
        ch = content[i]
        token = ""
        while isNumber(ch) or isCharacter(ch):
            token = token + ch
            i = i + 1
            ch = content[i]
        # print(token)
        if token in Dict.keys():
            print("(", token, ",", Dict[token], ")", file=f)
        else:
            print("(", "id", ",", 80, ")", file=f)
            index=Op_tablewrite(80,token)
        return i


# 读出整型常量
def Read_inte(content, i):
    with open(final_filename, "a") as f:
        ch = content[i]
        if ch == str(0):
            if not isNumber(content[i + 1]):
                if isCharacter(content[i+1]):
                    tempstring = ""
                    i=i+1
                    temp=content[i]
                    while isCharacter(ch) or isNumber(ch):
                        tempstring = tempstring + ch
                        i = i + 1
                        temp= content[i]
                    return Print_Error(5,i-1)
                else:
                    # print(0)
                    index = Op_tablewrite(20, 0)
                    print("(", "INT", ",", index, ")", file=f)
                    return i + 1
            else:
                i = i + 1
                while content[i] != "#":
                    if isNumber(content[i]):
                        i = i + 1
                    else:
                        break
                return Print_Error(1, i)
        else:
            integer = ""
            while isNumber(ch) and ch != "#":
                integer = integer + ch
                i = i + 1
                ch = content[i]
            if isCharacter(ch):
                tempstring = ""+integer
                temp = content[i]
                while isCharacter(temp) or isNumber(temp):
                    tempstring = tempstring + temp
                    i = i + 1
                    temp = content[i]
                return Print_Error(5, i - 1)
            else:
                # print(integer)
                index = Op_tablewrite(20, integer)
                print("(", "INT", ",", index, ")", file=f)
                return i


# 读出界限符或者运算符，不考虑字符串
def Read_Sign(content, i):
    with open(final_filename, "a") as f:
        token=""
        ch = content[i]
        token=token+ch
        value=Dict[token]
        if i+1>=len(content):
            return i + 1
        chnext = content[i + 1]
        if isOperator(ch):
            if isSign(chnext):
                i = i + 1
                while content[i] != "#":
                    if isSign(content[i]) or content[i]==" " or content[i]=="\n":
                        i = i + 1
                    else:
                        break
                return Print_Error(2, i - 1)
            else:
                print("(", ch, ",", value, ")", file=f)
                return i + 1
        elif isLS(ch):
            if ch != "!":
                if not isSign(chnext):
                    print("(", ch, ",", value, ")", file=f)
                    return i + 1
            if chnext == "=":
                if not isSign(content[i + 2]):
                    token=token+chnext
                    value=Dict[token]
                    print("(", token, ",", value, ")", file=f)
                    return i + 2
            elif chnext == "\"" and ch == "=":
                print("(", ch, ",", value, ")", file=f)
                return i + 1
            i = i + 1
            while content[i] != "#":
                if isSign(content[i]):
                    i = i + 1
                else:
                    break
            return Print_Error(2, i - 1)
        else:
            print("(", ch, ",", value, ")", file=f)
            return i + 1


# 读出字符串，注意前后”都没有读出
def Read_string(content, i):
    with open(final_filename, "a") as f:
        ch = content[i]
        value = Dict[ch]
        print("(", ch, ",", value, ")", file=f)
        i = i + 1
        string = ""
        while content[i] != "\"" and content[i] != "#":
            if (not isCharacter(content[i])) and (not isSign(content[i])):
                i = Print_Error(3, i)
            string = string + content[i]
            i = i + 1
        # print(string)
        if content[i] == "\"":
            index = Op_tablewrite(40, string)
            print("(", "STRING", ",", index, ")", file=f)
            print("(", ch, ",", value, ")", file=f)
            return i + 1
        else:
            return Print_Error(4, i - 1)


def Scanner(file_name):
    with open(file_name, "r") as f:
        content = f.read()
        # print(content)
        n = len(content)
        i = int(0)
        global line
        while (i < n) and (content[i] != "#"):
            if content[i] == " ":
                i = i + 1
            elif content[i] == "\n":
                line = line + 1
                i = i + 1
            elif (not isSign(content[i])) and (not isCharacter(content[i])) and (not isNumber(content[i])):
                i = Print_Error(3,i)
            else:
                ch = content[i]
                if isCharacter(ch):
                    i = Read_Key_or_ID(content, i)
                else:
                    if isNumber(ch):
                        i = Read_inte(content, i)
                    else:
                        if isSign(ch):
                            if ch == "\"":
                                i = Read_string(content, i)
                            else:
                                i = Read_Sign(content, i)
                        else:
                            i = Print_Error(3, i)
    if i==n and content[i-1]!="#":
        Print_Error(6,i-1)
    else:
        with open(final_filename, "a") as f:
            print("(", "#", ",", Dict["#"], ")", file=f)


def print_dict():
    with open(table_filename, "a") as f:
        print("+", "-" * 59, "+", sep="", file=f)
        print("+", " " * 20, "Encoding  Table", " " * 20, "+", file=f)
        print("+", "-" * 59, "+", sep="", file=f)
        print("| ", end="", file=f)
        count = 0
        for key, value in Dict.items():
            count = count + 1
            key_len = len(key)
            value_len = len(str(value))
            print(key, " " * (7 - key_len), value, " " * (3 - value_len), end="", sep="", file=f)
            print("| ", end="", sep="", file=f)
            if count % 5 == 0:
                print(file=f)
                print("+", "-" * 59, "+", sep="", file=f)
                print("| ", end="", sep="", file=f)
        print(" " * 9, "|", file=f)
        print("+", "-" * 59, "+", sep="", file=f)


def print_constants_table():
    with open(table_filename, "a") as f:
        print("+", "-" * 59, "+", sep="", file=f)
        print("+", " " * 20, "Constants Table", " " * 20, "+", file=f)
        print("+", "-" * 59, "+", sep="", file=f)
        
        print("+ ", end="", sep="", file=f)
        print(" " * 9, "INT Table", " " * 10, "+", sep="", end="", file=f)
        print(" " * 9, "STRING Table", " " * 8, "+", sep="", file=f)
        print("+", "-" * 59, "+", sep="", file=f)
        
        print("+", end="", sep="", file=f)
        print(" " * 4, "index", " " * 5, "|", sep="", end="", file=f)
        print(" " * 4, "token", " " * 5, sep="", end="", file=f)
        print("|", sep="", end="", file=f)
        print(" " * 4, "index", " " * 5, "|", sep="", end="", file=f)
        print(" " * 4, "token", " " * 5, "+", sep="", file=f)
        print("+", "-" * 59, "+", sep="", file=f)
        
        lengthi = len(INT_table)
        lengths = len(STRING_table)
        for i in range(max(lengthi, lengths)):
            print("|", sep="", end="", file=f)
            if i < lengthi:
                temp = len(str(i))
                print(i, " " * (12 - temp), end="", sep="", file=f)
                print("|", end="", sep="", file=f)
                temp = len(str(INT_table[i]))
                print(" " * 2, INT_table[i], " " * (12 - temp), end="", sep="", file=f)
            else:
                print(" " * 14, end="", file=f)
                print("|", end="", sep="", file=f)
                print(" " * 14, end="", file=f)
            print("|  ", sep="", end="", file=f)
            
            if i < lengths:
                temp = len(str(i))
                print(i, " " * (12 - temp), end="", sep="", file=f)
                print("|  ", end="", sep="", file=f)
                temp = len(str(STRING_table[i]))
                print(STRING_table[i], " " * (12 - temp), end="", sep="", file=f)
            else:
                print(" " * 12, end="", file=f)
                print("|", end="", sep="", file=f)
                print(" " * 14, end="", sep="", file=f)
            print("|", sep="", file=f)
            print("+", "-" * 59, "+", sep="", file=f)


def print_id_table():
    with open(table_filename, "a") as f:
        print("+", "-" * 59, "+", sep="", file=f)
        print("+", " " * 19, "Identifier  Table", " " * 19, "+", file=f)
        print("+", "-" * 59, "+", sep="", file=f)
        count = 0
        lent = len(ID_table)
        for i in range(lent):
            count = count + 1
            id = ID_table[i]
            lenid = len(id)
            leni = len(str(i))
            print("|  ", end="", sep="", file=f)
            print(i, " " * (27 - leni), "|  ", id, " " * (27 - lenid), sep="", end="", file=f)
            print("|", sep="", file=f)
            if count % 5 == 0:
                print("+", "-" * 59, "+", sep="", file=f)
                print("| ", sep="", file=f)
        print("+", "-" * 59, "+", sep="", file=f)


def main():
    file = open(final_filename, 'w').close()
    file = open(table_filename, 'w').close()
    file_name = "example.txt"
    Scanner(file_name)
    print_dict()
    print_constants_table()
    print_id_table()


main()

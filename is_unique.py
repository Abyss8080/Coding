def is_unique(di):
    string={}
    flag=True
    for strname in di.keys():
        value=di[strname]
        if value not in string.keys():
            string[value]=True
        else:
            return False
    return True

        
def main():
    dic1={"marty":"stepp","stuart":"reges","jessica":"wolk","allison":"obourn","hal":"perkins"}
    dic2={"kendrick":"perkins","stuart":"reges","jessica":"wolk","bruce":"reges","hal":"perkins"}
    print("is_unique(dic1)--->",is_unique(dic1))
    print("is_unique(dic2)--->",is_unique(dic2))

main()

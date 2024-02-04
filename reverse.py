def reverse(di):
    redi={}
    for kname in di.keys():
        value=di[kname]
        if value not in redi.keys():
            redi[value]=set()
        redi[value].add(kname)
    return redi

def main():
    di={42:"marty",81:"sue",17:"ed",31:"dave",56:"ed",3:"marty",29:"ed"}
    redi=reverse(di)
    print(redi)

main()

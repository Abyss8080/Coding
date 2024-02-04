def is_year(year):
        if year%400==0 or (year%4==0 and year%100!=0):
            return True
        return False
 
def days_in_month():
    month=int(input("the month is:"))
    m31='1,3,5,7,8,10,12'
    m30='4,6,9,11'
    if str(month) in m31.split(","):
        return 31
    elif str(month) in m30.split(","):
        return 30
    elif month==2:
        year=int(input("the year is:"))
        if is_year(year):
            return 29
        else:
            return 28

def main():
    print(days_in_month())

main()

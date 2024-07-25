#!/usr/bin/pyhon

def isLeapYear(year):
    if not(year % 4 == 0):
        return False
    elif (year % 100 == 0 and year % 400 != 0):
        return False
    return True

def daysInMonth(year, month):
    days_in_month = [31,28,31,30,31,30,31,31,30,31,30,31]
    if(isLeapYear(year)):
        days_in_month[1] = 29
    return(days_in_month[month-1])

def nextDay(year, month, day):
    """ Warning: this version assumes every month has 30 days"""
    if day < daysInMonth(year, month):
        return year, month, day + 1
    elif month < 12:
        return year, month + 1, 1
    else:
        return year + 1, 1, 1

def dateIsBefore(year1, month1, day1, year2, month2, day2):
    if year1 < year2:
        return True
    elif month1 < month2:
        return True
    else:
        return day1 < day2

def daysBetweenDates(year1, month1, day1, year2, month2, day2):
    assert not dateIsBefore(year2, month2, day2, year1, month1, day1)
    days = 0
    while dateIsBefore(year1, month1, day1, year2, month2, day2):
        year1, month1, day1 = nextDay(year1, month1, day1)
        days += 1
    return days

def codeTest(year1, month1, day1, year2, month2, day2, answer):
    try:
        result = daysBetweenDates(year1, month1, day1, year2, month2, day2)
        if result == answer and answer != "AssertionError":
            return "correct"
        else:
            return "incorrect"
    except AssertionError:
        if answer == "AssertionError":
            return "correct AssertionError"
        else:
            return "incorrect AssertionError"

print(daysBetweenDates(2011,6,30,2012,6,30))
print(codeTest(2011,6,30,2012,6,30,366))









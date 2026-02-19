# CS121_Project7

## UML Diagram
```
classDiagram
    Student --> Address
    Student --> Date
    
    class Address{
        - string street
        - string city
        - string state
        - string zip
        + Address()
        + void init(string street, string city, string state, string zip)
        + void printAddress()
    }
    class Date{
        - int month
        - int day
        - int year
        +  Date()
        + void init(string date)
        + void printDate()
    }
    
    class Student{
        - string firstName
        - string lastName
        - Address address
        - Date birthDate
        - Date gradDate
        - int credits
        + Student()
        + void init(string studentString)
        + void printStudent()
        + std::string getLastFirst(): string
    }
```

## Address::Address()
```
street = "N/A"
city = "N/A"
state = "N/A"
zip = "N/A"
```
## Address::init(string street, string city, string state, string zip)
```
street = street
city = city
state = state
zip = zip
```

## Address::printAddress()
```
print street
print city " " state ", " zip
```
## Date::Date()
```
month = 0
day = 0
year = 0
```
## Date::init(string stringDate)
```
read stringDate untill forward slash
convert string segment to an integer
put integer in month
read stringDate untill forward slash
convert string segment to an integer
put integer in day
read stringDate untill forward slash
convert string segment to an integer
put integer in year
```
## Date::printDate()
```
create array months of size 12 with each month
print months[month-1] " " day ", " year
```
## Student::Student()
```
firstName = "N/A"
lastName = "N/A"
```
## Student::init(string studentString)
```
read string until comma
put string segment in firstName
read string until next comma
put string segment in lastName

read string until next comma
put string segment in myStreet
read string until next comma
put string segment in myCity
read string until next comma
put string segment in myState
read string until next comma
put string segment in myZip

call init(myStreet, myCity, myState, myZip) for address

read string until next comma
put string segment in myBirthDate

call init(myBirthDate) for birthDate

read string until next comma
put string segment in myGradDate

call init(myGradDate) for gradDate

read string until next comma
convert string segment to int
put integer in credits
```
## Student::printStudent()
```
print firstName " " lastName
call printAddress for address
print "DOB: " and call printDate for birthDate
print "Grad: "  and call printDate for gradDate
print "Credits: " credits

```
## Student::getLastFirst()
```
print lastName ", " firstName

```

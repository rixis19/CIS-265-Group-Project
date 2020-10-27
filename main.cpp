#include <iostream>
#include <string>

using namespace std;

int     i_days          = 0,
        i_departure,
        i_return,
        i_miles;
double  d_seminar_fees  = 0,
        d_dinner_fees   = 0,
        d_excess        = 0,
        d_expense       = 0,
        d_saved         = 0,
        d_taxi_fees     = 0,
        d_lunch_fees    = 0,
        d_airfare       = 0,
        d_carfare       = 0,
        d_breakfast_fees= 0,
        d_parking       = 0;

//Matthew Pimentel,
void setExcess(double excess)
{
    d_excess = d_excess + excess;
}

//Matthew Pimentel,
double getExcess()
{
    return d_excess;
}

//Thomas Contey,
void setAllowableExpenses(double expense)
{
    d_expense = d_expense + expense;
}

//Thomas Contey,
double getAllowableExpenses()
{
    return d_expense;
}

//Thomas Contey,
double getExpense()
{
    return d_expense;
}

//Xuerou Chen,
void setSaved(double saved)
{
    d_saved = d_saved + saved;
}

//Lam,
double getSaved()
{
    return d_saved;
}

//Kevin Chicas
void setTotalDays()
{
    cout << "What is the total number of days spent on the trip?";
    cin >> i_days;
    while (i_days < 1)
    {
        cout << "Error! Value of days cannot be less than 1. Input again: ";
        cin >> i_days;
    }
    
    cout << endl;
}

//Kevin Chicas,
int getTotalDays()
{
    return i_days;
}

//Kevin Chicas,
void setSeminarFees()
{
    cout << "Please enter the amount of fees of any conferences or seminars for the day: $";
    cin >> d_seminar_fees;
    while(d_seminar_fees < 0)
    {
        cout << "Error! Negative numbers not accepted for dollar amount. Input again: $";
        cin >> d_seminar_fees;
    }
    
    setAllowableExpenses(d_seminar_fees);
    
    cout << endl;
}

//Kevin Chicas,
void setDinnerFees()
{
    cout << "How much was paid in dinner fees? $";
    cin >> d_dinner_fees;
    
    while(d_dinner_fees < 0)
    {
        cout << "Input cannot be zero, please re-input: $";
        cin >> d_dinner_fees;
    }
    
    if(d_dinner_fees > 16)
    {
        setExcess(d_dinner_fees - 16.00);
        setAllowableExpenses(16);
        
    }
    if(d_dinner_fees <= 16)
    {
        setAllowableExpenses(d_dinner_fees);
        
        setSaved(16 - d_dinner_fees);
    }
    
    cout << endl;
}

//Kevin Chicas,
double getTotalExpense()
{
    return getExpense() + getExcess();
}

//Matthew Pimentel,
void setMiles()
{
    int miles;
    double permiledriven = .27;
           
    cout << "How many miles did we drive in total? ";
    cin >> miles;
    
    while(miles < 0)
    {
        cout << "You must enter a number greater than 0. Input again: ";
        cin >> miles;
    }

    i_miles = miles;
    
    setAllowableExpenses(i_miles * permiledriven);
    
    cout << endl;
}

//Matthew Pimentel,
void setHotelExpenses()
{
    double HotelFee = 0;
    
    cout << "How much was spent on Hotel costs? $";
    cin >> HotelFee;
    
    while(HotelFee <= 0)
    {
        cout << "Please enter a number greater than 0! Input again: $";
        cin >> HotelFee;
    }
    
    if(HotelFee <= 90)
    {
        setSaved(90.00 - HotelFee);
        setAllowableExpenses(HotelFee);
    }
    else
    {
        setExcess(HotelFee - 90);
        setAllowableExpenses(90);
    }
    cout << endl;
}

//Lam,
void SetLeaveTime()
{
    cout<<"Enter time of departure in military time: (ex. 2359 is max) ";
    cin >> i_departure;
    cout << endl;
    
    while (i_departure <0 || i_departure > 2359 || i_departure % 100 > 59)
    {
        
            cout << "Error: Please enter a number between 0000 and 2359, where the last two digits are not above 59 as well: ";
            cin >> i_departure;
        
    }
    
    
}

//Lam,
void SetReturnTime()
{
    cout<<"Enter time of return in military time: (ex. 2359 is max)";
    cin >> i_return;
    
    while (i_return <0 || i_return > 2359 || i_return % 100 > 59)
    {
        cout << "Error: Please enter a number between 0000 and 2359, where the last two digits are not above 59 as well: ";
        cin >> i_return;
    }
    
    cout << endl;
}

//Lam,
void setTaxiFees()
{
    cout << "How much was paid in taxi fees? $";
    cin >> d_taxi_fees;
    
    while(d_taxi_fees < 0)
    {
        cout << "Invalid; Please enter a number greater than 0: $";
        cin >> d_taxi_fees;
    }
    
    if(d_taxi_fees > 10)
    {
        setExcess(d_taxi_fees - 10.00);
        setAllowableExpenses(10);
        
    }
    if(d_taxi_fees <= 10)
    {
        setAllowableExpenses(d_taxi_fees);
        
        setSaved(10 - d_taxi_fees);
    }
    
    cout << endl;
}

//Lam,
void setLunchFees()
{
    cout << "How much was paid in lunch fees? $";
    cin >> d_lunch_fees;
    
    while(d_lunch_fees < 0)
    {
        cout << "Invalid; Please enter a number greater than 0: $";
        cin >> d_lunch_fees;
    }
    
    if(d_lunch_fees > 12)
    {
        setExcess(d_lunch_fees - 12.00);
        setAllowableExpenses(12);
        
    }
    if(d_lunch_fees <= 12)
    {
        setAllowableExpenses(d_lunch_fees);
        
        setSaved(12 - d_lunch_fees);
    }
    
    cout << endl;
}

//Xuerou Chen
void setAirfareAmount ()
{
    cout << "\nWhat was the total cost of the air fare? $";
    cin >> d_airfare;
    // Input validation for the aiplane travel
    if(!(d_airfare>0.0) )
    {
        cout<<"\nInvalid input!\n";
        setAirfareAmount();
    }
    
    setAllowableExpenses(d_airfare);
    cout << endl;
}

//Xuerou Chen
void setCarRentalAmount()
{
    cout << "What was the total cost of any car rentals? $";
    cin >> d_carfare;
    //Input validation for the car rental amount
    while (d_carfare < 0)
    {
        cout << "Error:Please enter a number greater than 0. Try Again: $";
        cin >> d_carfare;
    }
    
    setAllowableExpenses(d_carfare);
    cout << endl;
}

//Xuerou Chen
void getBreakfastAmount()
{
    cout << "Enter the cost of breakfast: $";
    cin >> d_breakfast_fees;
    
    while(d_dinner_fees < 0)
    {
        cout << "Input cannot be zero, please re-input: $";
        cin >> d_breakfast_fees;
    }
        
    if(d_breakfast_fees < 9.00)
    {
        setSaved(9.00 - d_breakfast_fees);
        setAllowableExpenses(d_breakfast_fees);
    }
        
    else if(d_breakfast_fees > 9.00)
    {
        setExcess(d_breakfast_fees - 9.00);
        setAllowableExpenses(9);
    }
    
    cout << endl;
    
}

//Xuerou Chen
void getParkingAmount()
{
    cout << "Enter the cost of parking: $";
    cin >> d_parking;
    
    while(d_parking < 0)
    {
        cout << "Input cannot be zero, please re-input: $";
        cin >> d_parking;
    }
        
    if(d_parking < 6.00)
    {
        setSaved(6.00 - d_parking);
        setAllowableExpenses(d_parking);
    }
        
    else if(d_parking > 6.00)
    {
        setExcess(d_parking - 6.00);
        setAllowableExpenses(6);
    }
    cout << endl;
}

//Thomas Contey
int main(int argc, const char * argv[])
{
    int i_private_car_option = 0;
    int i_taxi_option = 0;
    
    setTotalDays();
    SetLeaveTime();
    SetReturnTime();
    setAirfareAmount();
    setCarRentalAmount();
    
    cout << "Was a private vehicle used? (0 = No, 1 = Yes) ";
    cin >> i_private_car_option;
    
    while (0 > i_private_car_option || i_private_car_option > 1)
    {
        cout << "Invalid. Try again. (0 = No, 1 = Yes) ";
        cin >> i_private_car_option;
    }
    cout << endl;
    if(i_private_car_option == 1)
    {
        setMiles();
    }
    
    cout << endl;
    
    for(int currentDay = 1; currentDay <= i_days; currentDay++)
    {
        cout << "Day " << currentDay << endl;
        getParkingAmount();
        
        cout << "Was a taxi used at all today? (0 = No, 1 = Yes) ";
        cin >> i_taxi_option;
        
        while (0 > i_taxi_option || i_taxi_option > 1)
        {
            cout << "Invalid. Try again. (0 = No, 1 = Yes) ";
            cin >> i_taxi_option;
        }
        cout << endl;
        if(i_taxi_option == 1)
        {
            setTaxiFees();
        }
        
        setSeminarFees();
        
        if(currentDay == 1)
        {
            if (i_departure <= 700)
            {
                getBreakfastAmount();
                setLunchFees();
                setDinnerFees();
            }
            else if (i_departure >= 700 && i_departure <= 1200)
            {
                setLunchFees();
                setDinnerFees();
            }
            else if (i_departure >= 1200 && i_departure <= 1800)
            {
                setDinnerFees();
            }
            cout << endl;
        }
        
        if(currentDay != 1 && currentDay != i_days)
        {
            getBreakfastAmount();
            setLunchFees();
            setDinnerFees();
        }
        
        if(i_days != 1 && currentDay == i_days)
        {
            if (i_return >= 1900)
            {
                getBreakfastAmount();
                setLunchFees();
                setDinnerFees();
            }
            else if (i_return <= 1900 && i_return >= 1300)
            {
                getBreakfastAmount();
                setLunchFees();
            }
            else if (i_return <= 1300 && i_return >= 800)
            {
                getBreakfastAmount();
            }
            cout << endl;
        }
        
        if(currentDay != i_days)
        {
            setHotelExpenses();
        }
        
        cout << endl;
    }
    
    cout << "Total Expenses incurred during trip: $" << getAllowableExpenses() + getExcess() << endl;
    cout << "Total Allowable Expenses incurred during trip: $" << getAllowableExpenses() << endl;
    cout << "Total excess expenses that must be reimbrused: $" << getExcess() << endl;
    cout << "Total amount saved in business trip expenses: $" << getSaved() << endl;
    
    cout << endl << endl;
    
}

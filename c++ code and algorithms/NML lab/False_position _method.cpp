// C++ program for implementation of False Position Method for
// solving equations
#include<bits/stdc++.h>
using namespace std;


bool isNearZero(double value, double epsilon = 1e-3)
{
    return abs(value) < epsilon;
}
string createPolynomial(int degree, const vector<double>& coefficients)
{
    string polynomial;

    for (int i = 0; i <= degree; ++i)
    {
        if (i > 0)
        {
            polynomial += " + "; // Add '+' for subsequent terms
        }
        polynomial += to_string(coefficients[i]) + "*x^" + to_string(i); // Construct the term
    }

    return polynomial; // Return the polynomial as a string
}

double evaluatePolynomial(int degree, const vector<double>& coefficients, double x)
{
    double result = 0.0;

    for (int i = 0; i <= degree; ++i)
    {
        result += coefficients[i] * pow(x, i); // Calculate the value of the polynomial
    }

    return result; // Return the evaluated result
}


// Prints root of func(x) with error of EPSILON
int  falseposition(double a, double b,int degree, const vector<double>& coefficients,int cnt,double EPSILON)
{
    if (evaluatePolynomial(degree,coefficients, a) * evaluatePolynomial(degree,coefficients, b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return cnt;
    }
   // int Enter=0;
    double c = a;
    while (abs((b-a)/b) >= EPSILON)
    {
        // cout<<"funny"<<endl;
        double fb=evaluatePolynomial(degree,coefficients, b);
        double fa=evaluatePolynomial(degree,coefficients, a);

        // Find middle point
        c = (a*fb - b*fa)/ (fb - fa);
        //Enter=1;
        // Check if middle point is root
        double fc=evaluatePolynomial(degree,coefficients, c);
        if (isNearZero(fc))
            break;

        // Decide the side to repeat the steps
        else if (fc*fa < 0)
            b = c;
        else
            a = c;
    }
    if(1)
    {
        cout << "The value of root is : " << c<<endl;
        return cnt+1;
    }
    // Enter=0;
}

// Driver program to test above function
int main()
{
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    cout<<"Enter the value of epsilon:";
    double EPSILON;
    cin>>EPSILON;

    vector<double> coefficients(degree + 1);
    for (int i = 0; i <= degree; ++i)
    {
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coefficients[i];
    }

    string polynomialEquation = createPolynomial(degree, coefficients);
    cout << "The polynomial equation is: " << polynomialEquation << endl;

    //interval
    double y;

    y=abs(sqrt(((coefficients[degree-1]/coefficients[degree])*(coefficients[degree-1]/coefficients[degree]))-2*(coefficients[degree-2]/coefficients[degree])));
    //vector<int>value((int)y+(int)y+1);
    int cnt=0;
    int round=1;

    while(cnt!=degree)

    {

        if(round==1)
        {

            for(int i=-y; i<=0; i++)
            {
                cnt=falseposition(i,i+1,degree,coefficients,cnt,EPSILON);
                if(cnt>=0 && cnt<(degree/2))
                {
                    round=2;
                    continue;
                }
                else
                {
                    round=2;
                    break;
                }


            }
        }
        else if(round==2)
        {
            for(int i=y-1; i>0; i--)

            {
                cnt=falseposition(i,i+1,degree,coefficients,cnt,EPSILON);
                if(cnt>=(degree/2) && cnt<degree)
                    continue;
                else
                    break;
            }
        }
    }


}





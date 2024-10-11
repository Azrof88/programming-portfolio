#include <bits/stdc++.h>
#include <cmath> // for the abs() function
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


vector<double> calculateDerivative(const vector<double>& coefficients)
{




    vector<double> derivative;
    for (int i = 1; i < coefficients.size(); ++i)
    {
        derivative.push_back(coefficients[i] * i);
    }
    return derivative;
}

double evaluateDerivative(const vector<double>& derivativeCoefficients, double x)
{
    double result = 0.0;
    for (int i = 0; i < derivativeCoefficients.size(); ++i)
    {
        result += derivativeCoefficients[i] * pow(x, i);
    }
    return result;
}
// Function to find the root
double newtonRaphson(double initialGuess, double tolerance, int maxIterations,int degree,int cnt,const vector<double>& coefficients,const vector<double>& derivativeCoefficients)
{
    //cout<<"ghgjhvfghghg"<<endl;

    double x = initialGuess;// Initial guess
    if( evaluateDerivative(derivativeCoefficients,x)==0)
    {
        return cnt;
    }
    double h = evaluatePolynomial(degree,coefficients,x) / evaluateDerivative(derivativeCoefficients,x);
    double x1=x-h;
    double temp1=0;
    temp1=x1;
    x1=x;
    x=temp1;

    int iteration = 0;

    // Iterate until the value is close to zero within the given tolerance or until max iterations are reached
    while (abs((x1-x)/x) >= tolerance && iteration < maxIterations)
    {
        h = evaluatePolynomial(degree,coefficients,x) / evaluateDerivative(derivativeCoefficients,x);

        // x(i+1) = x(i) - f(x) / f'(x)
        double x1=x-h;
        double temp=0;
        temp=x1;
        x1=x;
        x=temp;
        //x = x - h;
        iteration++;
    }

    cout<<"The root i :"<<x<<endl;
    return cnt+1;
}







int main()
{
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    cout<<"Enter the value of tolerance:";
    double tolerance;
    cin>>tolerance;
    cout<<"Enter maximum iteration:"<<endl;
    int maxIterations;
    cin>>maxIterations;

    vector<double> coefficients(degree + 1);
    for (int i = 0; i <= degree; ++i)
    {
        cout << "Enter coefficient for x^" << i << ": ";
        cin >> coefficients[i];
    }

    string polynomialEquation = createPolynomial(degree, coefficients);
    cout << "The polynomial equation is: " << polynomialEquation << endl;

    vector<double> derivativeCoefficients = calculateDerivative(coefficients);

    //interval
    double y;

    y=abs(sqrt(((coefficients[degree-1]/coefficients[degree])*(coefficients[degree-1]/coefficients[degree]))-2*(coefficients[degree-2]/coefficients[degree])));
    vector<int>value((int)y+(int)y+1);
    int cnt=0;
    int round=1;
    while(cnt!=degree)
    {
        //cout<<"Funny"<<endl;
        if(round==1)
        {
            for(int i=-y+1; i<=0; i++)
            {
                cnt=newtonRaphson(i,tolerance,maxIterations,degree,cnt,coefficients,derivativeCoefficients);
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
                cnt=newtonRaphson(i,tolerance,maxIterations,degree,cnt,coefficients,derivativeCoefficients);
                if(cnt>=(degree/2) && cnt<degree)
                    continue;
                else
                    break;
            }
        }

    }





return 0;
}

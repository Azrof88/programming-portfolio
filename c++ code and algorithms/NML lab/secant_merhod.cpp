// C++ Program to find root of an
// equations using secant method
#include <bits/stdc++.h>
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
    //cout<<"result="<<result<<endl;

    return result; // Return the evaluated result
}

// function takes value of x and returns f(x)
float f(float x)
{
    // we are taking equation as x^3+x-1
    float f = pow(x, 3) + x - 1;
    return f;
}

int secant(double x0,double x1,double E,int maxIterations,int degree,int cnt,const vector<double>& coefficients)
{
    double n = 0, xm, x2, c;
    //cout<<((evaluatePolynomial(degree,coefficients,x0)) * (evaluatePolynomial(degree,coefficients,x1))) <<endl;
    if (((evaluatePolynomial(degree,coefficients,x0)) * (evaluatePolynomial(degree,coefficients,x1))) < 0)
    {
        do
        {
            double fx1=evaluatePolynomial(degree,coefficients,x1);
            double fx0=evaluatePolynomial(degree,coefficients,x0);
            // calculate the intermediate value
            x2 = x1-(((x1 - x0) *fx1) / (fx1 -fx0));

            // check if x2 is root of equation or not
            c = evaluatePolynomial(degree,coefficients,x2);

            // update the value of interval
            x0 = x1;
            x1 = x2;

            // update number of iteration
            n++;

            // if x0 is the root of equation then break the loop
            if (isNearZero(c))
            {

                break;
            }
            fx1=evaluatePolynomial(degree,coefficients,x1);
            fx0=evaluatePolynomial(degree,coefficients,x0);
            xm =  x1-(((x1 - x0) *fx1) / (fx1 -fx0));
        }
        while (fabs(xm - x2) >= E);   // repeat the loop
        // until the convergence

        cout << "Root of the given equation=" << x2 << endl;
        //cout << "No. of iterations = " << n << endl;
        return ++cnt;
    }
    else
    {
        cout << "Can not find a root in the given interval"<<endl;
        return cnt;
    }
}

// Driver code
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

    double y;

    y=abs(sqrt(((coefficients[degree-1]/coefficients[degree])*(coefficients[degree-1]/coefficients[degree]))-2*(coefficients[degree-2]/coefficients[degree])));
    vector<int>value((int)y+(int)y+1);
    int round=1;
    int cnt=0;
    int cnt1;
    while(cnt!=degree)
    {
        //cout<<"Funny"<<endl;
        if(round==1)
        {
            for(int i=-y; i<=0; i++)
            {
                cnt=secant(i,i+1,tolerance,maxIterations,degree,cnt,coefficients);
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
            for(int i=y; i>0; i--)

            {
                cnt=secant(i,i-1,tolerance,maxIterations,degree,cnt,coefficients);
                if(cnt>=(degree/2) && cnt<degree)
                    continue;
                else
                    break;
            }
        }

    }
    // initializing the values

}

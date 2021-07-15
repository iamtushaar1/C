#include <iostream> 
#include <cmath> // used for math functions used in the code

using namespace std;

class Guitar // This is where the guitar class is initiated
{
    private:
        char numberOfFrets;
        double A;
        double B; 
        double G; 
        double D;
        double E0; 
        double E; 

    public:
        Guitar() 
    {
        E0= 82.41;

        A = 110;

        D = 146.8;

        G = 196;

        B = 246.9; 

        E = 329.6;

        numberOfFrets= 21;
    }

    bool setFretBoardLength(const unsigned char numFrets)   // this method varifies whether the input field is between 1 and 24
    {
    if (numFrets>=1 && numFrets <=24) 
        {
        numberOfFrets = numFrets;
        return true;
        }
    else 
        {
        return false;
        }
    }

    int getFretLength() {
        return (int)numberOfFrets;
    }
    
    void getStrings() 
    {
        cout << "E " << E0 << " Hz" << endl;
        cout << "A " << A << " Hz" << endl;
        cout << "D " << D << " Hz" << endl;
        cout << "G " << G << " Hz" << endl;
        cout << "B " << B << " Hz" << endl;
        cout << "E " << E << " Hz" << endl;
    }

    double getFreq(int i) 
    {
        switch (i) 
        {
            case 1:
                return E0;
            case 2:
                return A;

            case 3:
                return D;
            case 4:
                return G;
            case 5:
                return B;
            case 6:
                return E;
            default:
                cout << "Invalid input. Use 1 to 6." << endl;
                return -1.0;
        }
    }

    double pitchAt(const unsigned char &stringNumber, const unsigned char &fret) // for a given string and fret, this method returns the frequency for the same 
    {
        double x = fret/12.0;
        double times = pow(2,x);

        if(stringNumber >=1 && stringNumber <= 6)
        {
            if ((int)fret <= (int)numberOfFrets && (int)fret >= 0)
            {
                return (getFreq((int)stringNumber) * times);
                
            }
            else // works only when the number of fret is smaller than 0
            {
                cout << "fret number invalid" << endl;
                return -1.0;
            }
        }
        else // works only when the stringnumber is less than 1 or greater than 6
        {
            return -1.0;
            cout << "String number invalid, enter between 1 and 6" << endl;
        }
    }

    /*pair <char, int> getStringAndFret (double pitch)
    {

    }*/

    void tuneString(unsigned char string, const double& pitch ) // for each string the tuning can be changed using this method
    {
        if ((int)string <=1 && (int)string >=6)
        {
            cout << "Invalid number. Enter between 1 and 6.";
        } 
        else 
        {
            switch ((int)string) 
            {
                case 1:
                    E0 = pitch;
                    break;
                case 2:
                    A = pitch;
                    break;
                case 3:
                    D = pitch;
                    break;
                case 4:
                    G = pitch;
                    break;
                case 5:
                    B = pitch;
                    break;
                case 6:
                    E = pitch;
                    break;
                default:
                    cout << "Invalid input. Use 1 to 6." << endl;
                    break;
            }
        }
    }
};

 int main() { // main method
        Guitar aGuitar;
        cout << " " << endl;
        cout << "We have created a guitar with the following string and 21 frets." << endl;
        aGuitar.getStrings();
        cout << " " << endl;
        cout << "Change the number of frets to 19." << endl;
        aGuitar.setFretBoardLength(19);
        cout << "Fret board length changed to " << aGuitar.getFretLength() << endl;
        cout << " " << endl;
        cout << "Find the Pitch at string 3 on fret 5." << endl;
        cout << aGuitar.pitchAt(1,5) << endl;
        char cString = 3;
        cout << " " << endl;
        cout << "Change the tune of a string. Change string 3 to 450 Hz" << endl;
        aGuitar.tuneString(cString,450.0);
        aGuitar.getStrings();



        return 0;
}
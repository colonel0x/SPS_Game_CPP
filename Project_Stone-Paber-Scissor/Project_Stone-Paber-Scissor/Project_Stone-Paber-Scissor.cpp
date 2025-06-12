#include <iostream>
using namespace std;



enum enChoseOption { VictoryU = 1, VictoryC = 2, Draw = 3 };
enum enRoulseTheGame { stone = 1, Paper = 2, Scisser = 3 };

int RandomNumber(int from, int to) {


    int randNum = (rand() % (to - from + 1)) + from;
    return randNum;

}

void  RandomRoundGameSPS(int &NumC) {

     NumC = RandomNumber(1, 3);



}



int ReadFromPlayerHowMuchRoundWant() {
    int Round = 0;



    cout << "\n                    *** Welcom to Game 'SPS' ***\n";
    do
    {
        cout << "How Many Round do you want: ";
        cin >> Round;
    } while (Round < 0);

    return Round;

}


int StartToPlay_UserVSComputer_U(int i) {

    int Num = 0;
    do
    {

        cout << "\n\nRound[" << i << "]" << "Begin\n\n";
        cout << "Your Choice:  Stone(1), Paper(2), Scisser(3)\n Enter: ";
        cin >> Num;

    } while (Num <= 0 || Num > 3);
    return Num;

}


int StartToPlay_ComputerVSUser_C() {
    
    int NumC = 0;
    RandomRoundGameSPS(NumC);
    return NumC;

}

int ShowResultRoundAndRegisterThem(int ChoiceUser, int ChoiceComputer) {



  

    //stone
   
    if (ChoiceUser == enRoulseTheGame::stone && ChoiceComputer == enRoulseTheGame::Paper)
    {
        return enChoseOption::VictoryC;
    }
    else if (ChoiceUser == enRoulseTheGame::stone && ChoiceComputer == enRoulseTheGame::Scisser) {

        return enChoseOption::VictoryU;
    }

  //Paper
    else if (ChoiceComputer == enRoulseTheGame::Paper && ChoiceUser == enRoulseTheGame::Scisser)
    {
        return enChoseOption::VictoryU;

    }
    else  if (ChoiceComputer == enRoulseTheGame::Paper && ChoiceUser == enRoulseTheGame::stone)
    {
        return enChoseOption::VictoryC;
    }




    //Scisser
    else  if (ChoiceComputer == enRoulseTheGame::Scisser && ChoiceUser == enRoulseTheGame::Paper)
    {

        return enChoseOption::VictoryC;

    }
    else  if (ChoiceComputer == enRoulseTheGame::Scisser && ChoiceUser == enRoulseTheGame::stone)
    {

        return enChoseOption::VictoryU;

    }
    else  if (ChoiceUser == enRoulseTheGame::Scisser && ChoiceComputer == enRoulseTheGame::stone)
    {

        return enChoseOption::VictoryC;

    }
    




    // Draw!!
    else if (ChoiceUser == 1 && ChoiceComputer == 1)
    {
        return  enChoseOption::Draw;


    }
    else if (ChoiceUser == 2 && ChoiceComputer == 2)
    {
        return  enChoseOption::Draw;


    }
    else if (ChoiceUser == 3 && ChoiceComputer == 3)
    {
        return  enChoseOption::Draw;


    }

      

    



}



string Know_What_the_User_Choice(int ChoiceU){


    if (ChoiceU == 1){

        return "Stone";
    }
    else if (ChoiceU == 2) {
        return "Paper";
    }
    else if (ChoiceU == 3) {
        return "Scisser";
    }

}

string Know_What_the_Computer_Choice(int ChoiceC) {


    
     if (ChoiceC == 1) {

        return "Stone";
    }
    else if (ChoiceC == 2) {
        return "Paper";
    }
    else if (ChoiceC == 3) {
        return "Scisser";
    }


}

string WhoIsWinner(int User,int Computer){


    if (User > Computer)
    {
        return "Player_1";
      

    }
    else if (Computer > User)
    {
        return "Computer";
    
    }
    else {
        return "No winner!!";
    }


}


void RingAndChangeTheColor(enum enChoseOption,int ChoiceU,int ChoiceC,int Round,int i) {


    if (ShowResultRoundAndRegisterThem(ChoiceU,ChoiceC) == enChoseOption::VictoryU)
    {
        system("color 2F");
      // Green
    }
    else if (ShowResultRoundAndRegisterThem(ChoiceU, ChoiceC) == enChoseOption::VictoryC) {
          
        system("color 4F");
        system("echo \a");
        

    }
    else if(ShowResultRoundAndRegisterThem(ChoiceU, ChoiceC) == enChoseOption::Draw)
    {
        system("color 6");

    }
    cout << "____________ Round [ " << i << " ] __________";
    cout << "\n\nPlayer_1 Choice: " << Know_What_the_User_Choice(ChoiceU);
    cout << "\nComputer Choice: " << Know_What_the_Computer_Choice(ChoiceC);
    cout << "\nRound winner: " << WhoIsWinner(ChoiceU, ChoiceC) << "\n___________________________________" << endl;

}



void GameOverShowResults(short User_Victory_Register, short Computer_Victory_Register, short Draw, int Round) {


    cout << "\n         _______________________________________________________";
    cout << "\n        |                                                       |";
    cout << "\n        |               +++  G A M E  O V E R  +++              |";
    cout << "\n        |_______________________________________________________|\n";


    cout << "\n\n         ______________________[Game Results]____________________         ";
    cout << "\n\                     Game Rounds               : " << Round;
    cout << "\n                      User_1 victorys time     : " << User_Victory_Register;
    cout << "\n                      Computer victorys time   : " << Computer_Victory_Register;
    cout << "\n                      Draw Time                : " << Draw;
    cout << "\n                      Finnal Winner            : " << WhoIsWinner(User_Victory_Register, Computer_Victory_Register);

    cout << "\n\n\n\n" << endl;



}



void StartGame_SPS() {

    int Round = ReadFromPlayerHowMuchRoundWant();
    int ChoiceFromUser     = 0;
    int ChoiceFromComputer = 0;
    short User_Victory_Register = 0,
        Computer_Victory_Register = 0,
        Draw = 0;
    

    
    for (int i = 1; i <= Round; i++)
    {
        ChoiceFromUser = StartToPlay_UserVSComputer_U(i);
        ChoiceFromComputer = StartToPlay_ComputerVSUser_C();

        if (ShowResultRoundAndRegisterThem(ChoiceFromUser, ChoiceFromComputer) == enChoseOption::VictoryU) {
            
            ++User_Victory_Register;
            
            RingAndChangeTheColor(enChoseOption::VictoryU,ChoiceFromUser,ChoiceFromComputer,Round,i);
            

        }
        else if(ShowResultRoundAndRegisterThem(ChoiceFromUser, ChoiceFromComputer) == enChoseOption::VictoryC)  {
            
            ++Computer_Victory_Register;

            RingAndChangeTheColor(enChoseOption::VictoryC, ChoiceFromUser, ChoiceFromComputer, Round,i);
            

        }
        else if (ShowResultRoundAndRegisterThem(ChoiceFromUser, ChoiceFromComputer) == enChoseOption::Draw)
        {
            ++Draw;

            RingAndChangeTheColor(enChoseOption::Draw, ChoiceFromUser, ChoiceFromComputer, Round,i);
            
        }

    }

    GameOverShowResults(User_Victory_Register, Computer_Victory_Register, Draw, Round);
  
}

void GameLancher() {
    string PlayAgin;

    StartGame_SPS();

   
    do
    {

        cout << "Do you want play agin? Y/N: ";
        cin >> PlayAgin;


        if (PlayAgin == "Y" || PlayAgin == "yes")
        {
            system("cls");
            system("color 0F");
            StartGame_SPS();



        }
        else if (PlayAgin == "N" || PlayAgin == "No")
        {
            system("cls");
            system("color 0F");
            cout << "\nHave a good day\n";
        }



    } while (PlayAgin == "Y" || PlayAgin == "Yes");

}



int main() {
    srand((unsigned)time(NULL));

   

    GameLancher();


}
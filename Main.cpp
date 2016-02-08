//<insérer ici un texte long et inutile sur le fait que le programme m'appartient... Il y a un exeemple plus bas mais le fautes en moins et une license mais pas 4 serait la bienvenue. BREF>

/* This program and his code his the propriety of Jules Blasco Déjoué. He is the Only one who can post it or share it without mentioned himself. Every copy of a part or of
the whole program or code is forbidden except ant special authorization delivered by the owner of this code called Jules Blasco Déjoué. In case of any litiges,
they will be solved according to the French Legslitature*/

#include <iostream>
#include <string>

using namespace std;

char askside()
{
    char lane;
    bool again;
    do{
        getline(cin,lane);
        if(lane=='C'||lane=='c'||lane =='CT'||lane=='ct')
        {
            lane='C';
            again=false;
        }
        else if (lane=='T'||lane=='t')
        {
            lane ='T';
            again=false;
        }
        else
        {
            cout<<"OOPS ! It seems you have done a mistake...Please type only C or T again.";
            again=true;
        }
    }while(again=false);

    return lane;
}

int main()
{
    char side;
    int row_res, money_O(800),money_E(800),rowWon,rowLost;

    /*  ================VARIABLE UILISEES ACTUELLEMENT================
        row_res = Les résultats du round entrées par l'utilisateur grâce aux différentes propositions;
        money_O = Moyenne d'argent que devrait posséder chaque personne de votre équipe;
        money_E = Moyenne d'argent que devrait posséder chaque personne de l'équipe adverse;
        rowWon = Nombre de rounds gagnés d'affilés;
        rowLost = Nombre de rounds perdus d'affilés;
        side = Côté du joueur (CT ou T) prenant les valeurs vérifiés par la fonction askside
        ==============VARIABLES UTILISESES PROCHAINEMENT==============
        mooney_OT = Argent total théorique possédé par votre équipe basée sur la multiplication de money_O par 5 et l'ajout des revenus spéciaux (désamorçage ou actions)
        mooney_ET = Argent total théorique possédé par l'équipe ennemie basée sur la multiplication de money_E par 5 et l'ajout des revenus spéciaux (désamorçage ou actions)
        rowWonT = Nombre de rounds gagnés au total
        rowLostT = Nombre de rounds perdus au total
        ==============A STOCKE DANS LE FICHIER==============
        kills = Nombre de kills du joueur
        assists = Nombre d'assistance du joueur
        deaths = Nombre de morts du joueur
        MVP = Nombre d'étoiles MVP reçus par le joueur
    */

    cout<<"Hello, I hope you are ready for a new Matchmaking on Counter Strike::Global Offensive." <<endl;
    cout<<"As you know, the management of the money in CS:GO is one of the most important and one of the hardest thing in that game."<<endl<<endl;
    cout<<"So, I have created this program to help you to managed your money and give you info about the ennemy's money." <<endl<<endl<<"Good Luck Have Fun!!";
    cout<<endl<<endl<<"-------------------------------------------------------------------------------"<<endl<<endl;
    cout<<"So, let's begin : are you C or T ?";
    cin>>side;//faire un vérificateur à l'aide d'une fonction
    side=askside();

    cout<<"OK, Do you have : (type the number of your answer)"<<endl<<"1. Winning by killing all opponents;" <<endl;
    if (side=='C')
    {
        cout<<"2. Winning by defusing the bomb;"<<endl<<"3. Winning by waiting the end of the timer;"<<endl<<<<endl<<"Losing the row;";
    }
    else//ATTENTION AU 2 NUMEROS 3, ILS N'ONT PAS LE MEME REVENU !!!!!!!!!!!
    {
        cout<<"2. Winning by make exploding the bomb;"<<endl<<<<endl<<"3. Losing after planting the bomb;"<<endl<<"4. Losing without planting the bomb;"<<endl;
    }
    cin>>row_res;

    //Faire de la valeur de l'agrent gagné par les T une variables.


    switch
    {
        case 1:
            ++rowWon;
            rowLost=0;
            money_O+=3250;
            if (rowWon=<5)
            {
                money_E+=3500;
            }
            else
            {
                money_E=money_E+1400+500*rowWon;
            }
        break;
        case 2:
            money_O+=3500;
            if (side='C'&&rowWon=<5)
            {
                money_E=money_E+2200+500*rowWon;
            }
            else
            {
                money_E+=1400;
            }
/*             ++rowWon;
 *             rowLost=0;
 */
        break;
        case 3:
            if(side='C')
            {
                money_O+=3250;
                money_E+=1400;
                ++rowWon;
                rowLost=0;
            }
            else
            {
                money_O+=1400//Vérifier cette valeur (revenu si attente à la fin du round en terro)
                money_E+=3250
                ++rowLost;
                rowWon=0;
            }
        break;
        case 4:
            {
                money_O+=1400;
                money_E+=3250;
                ++rowLost;
                rowWon=0;
            }
    }

    if (tLost=true&&side='T'&&rowLost=<5)//SI on  à perdu ET que l'on et Terro ET que l'on a enchaine +ou- 5 défaites alors +3400
    {//VERIFIER L'IMPORTANCE DE TERRO OU CT
        money_O+=3400;
    }

    else if (tLost=true&&side='C'&&rowWon=<5)//SI les T ont perdu ET que l'on est CT ET que l'on a enchaine +ou- 5 victoies alors +3400 pour les ennemis
    {
        money_E+=3400;
    }
    else if (tLost=true&&side='T'&&rowLost=>4)
    {
        money_O=money+1400+500*rowLost;
    }
    else if (tLost=true&&side='C'&&rowWon=>4)
    {
        money_E=money+1400+500*rowWon;
    }
    cout<<"Did someone has done something impressive (3k,4k,ace,knife kill)";

    return 0;
}

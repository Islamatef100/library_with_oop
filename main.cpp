#include <iostream>
#include <string>
using namespace std;
//**************************
string borrowered;
int indx, er_ad;
//**************************
//base class:
class Library
{
protected:
    string  Library_ID, Name;
public:
    Library();
    void set_Library_ID();
    void set_Name();
    string get_Library_ID();
    string get_Name();
};
class subscriber
{
protected:
    string type[50], name[50], address[50], phone[50], email[50], borrowed_items[50];
    long int time[50] = { 0 }, fee[50] = { 0 }, id[50] = { 0 };

public:
    subscriber();
    long int conv_str_int(int n_id, string ID);
    void print(int i);
    void search();
    void edit();
    void add();
    void borrow(int err_book);
    int return_borrowed_item(int t);
    void payment();
    void _delete(int del_ret_b, int index);
    void print_reports();

};
class contents
{
protected:
    long int Item_ID[120] = { 0 }, Production_Year[120];
    string  Category[120], Author[120], Publisher[120];
    string  Status[120];
public:
    string Title[120];
    long int  Copies[120];
    contents();
    long int conv_str_int(int tc, string ID);
    void print_sections(int start, int end);
    void edit(int start, int end);
    void _delete(int start, int end, int dele, int j);
    void search(int start, int end);
    void add(int start, int end, int old_book);
    void interface();
    string get();
};

//child class of contents:
class Arts_and_Architecture :public contents
{
public:
    Arts_and_Architecture();
};
class Computer_Science_and_Engineering :public contents
{
public:
    Computer_Science_and_Engineering();
};
class Business_and_Economics :public contents
{
public:
    Business_and_Economics();
};
class Science_and_Mathematics :public contents
{
public:
    Science_and_Mathematics();
};
class Education :public contents
{
public:
    Education();
};
class General_and_News :public contents
{
public:
    General_and_News();
};

//outside class Library:
//*************************************************************
Library::Library()
{
    Library_ID = "0";
    Name = "0";
}
void Library::set_Library_ID()
{
    cout << "please enter Library ID:" << endl;
true_id:
    getline(cin, Library_ID);
    system("color E");
    if (Library_ID != "islam atef")
    {
        system("color 04");
        cout << "Error==> please enter a true Library_ID:" << endl;
        goto true_id;
    }
}
void Library::set_Name()
{
    Name = "Fayoum University Library";
}
string Library::get_Library_ID()
{
    return Library_ID;
}
string Library::get_Name()
{
    return Name;
}
//*************************************************************

//outside class subscriber:
//*************************************************************
subscriber::subscriber()
{
    id[0] = 1;  id[1] = 2;    id[2] = 3;  id[3] = 4;  id[4] = 5;
    type[0] = "golden";  type[1] = "golden";  type[2] = "normal"; type[3] = "normal"; type[4] = "golden";
    name[0] = "ayman";    name[1] = "youssef";     name[2] = "islam";    name[3] = "mostafa";     name[4] = "hamada";
    address[0] = "cairo"; address[1] = "octobar";  address[2] = "giza"; address[3] = "london";  address[4] = "fayoum";
    phone[0] = "01069807034";  phone[1] = "01551080257";  phone[2] = "01063914191"; phone[3] = "01124182532"; phone[4] = "01112621398";
    email[0] = "am5432@fayoum.edu.eg";  email[1] = "yf123@fayoum.edu.eg";  email[2] = "is@fayoum.edu.eg";  email[3] = "mm@fayoum.edu.eg"; email[4] = "hm@fayoum.edu.eg";
    // borrowed_items[0] = "introduction to computer science"; borrowed_items[1] = "building types"; borrowed_items[2] = "entrepreneur"; borrowed_items[3] = "training strategies"; borrowed_items[4] = "software & technology";
    // time[0] = 50; time[1] = 100; time[2] = 30; time[3] = 40; time[4] = 80;
    for (int i = 5; i < 50; i++)
    {
        type[i] = "0"; name[i] = "0"; address[i] = "0"; phone[i] = "0"; email[i] = "0"; borrowed_items[i] = "0";
    }
}
long int subscriber::conv_str_int(int n_id, string ID)
{
a:
    string str = "0"; long int int_var = 0;
    long int y[10] = { 0 }, b = 0, j = 0;

    int_var = 0;
    if (n_id == 1)
    {
        str = ID;
        if (str.length() > 3)
        {
            b = 2;
        }
    }
    else
    {
        getline(cin, str);
    }
    system("color E");
    if (b != 2)
    {
        j = str.length() - 1;
        for (int s = 0; s < str.length(); s++)
        {
            y[s] = str[j];

            if (y[s] < 48 || y[s]>57)
            {
                b = 1;
            }
            else
            {
                y[s] = y[s] - 48;
            }
            j--;
        }
        int malt = 1;
        if (b == 1 || str.length() > 10)
        {
            if (n_id != 1)
            {
                system("color 04");
                cout << "Error==>please enter a true time:" << endl;
                goto a;
            }
        }
        if (b != 1)
        {
            for (int s = 0; s < str.length(); s++)
            {
                y[s] = y[s] * malt;
                malt = malt * 10;
                int_var += y[s];
            }
        }
    }
    return int_var;
}
void subscriber::print(int i)
{
    cout<< "|-------------------------------------------------------------------|" << endl
        << "| ID        \t\t\t | " << id[i] << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| type      \t\t\t | " << type[i] << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| name      \t\t\t | " << name[i] << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| address   \t\t\t | " << address[i] << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| phone     \t\t\t | " << phone[i] << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| email     \t\t\t | " << email[i] << endl
        << "|-------------------------------------------------------------------|" << endl
        << "| borrowered_items  \t\t | " << borrowed_items[i] << endl
        << "|-------------------------------------------------------------------|" << endl;
    cout<< "| the total borrowered time is:\t | " << time[i] << " days" << endl
        << "|-------------------------------------------------------------------|" << endl;
    //********************************************************************************************
    if (type[i] == "normal")
    {
        //three weeks:
        if (time[i] > 21)
        {
   cout << "| The delay period:\t\t | '" << time[i] - 21 << "' days" << endl
        << "|-------------------------------------------------------------------|" << endl;
        }
        else
        {
            cout << "| The delay period:\t\t | " << "<There is no delay>" << endl
                 << "|-------------------------------------------------------------------|" << endl;
        }
    }
    else if (type[i] == "golden")
    {
        //three months:
        if (time[i] > 90)
        {
            cout << "| The delay period:\t\t | '" << time[i] - 90 << "' days" << endl
                 << "|-------------------------------------------------------------------|" << endl;
        }
        else
        {
            cout << "| The delay period:\t\t | " << "<There is no delay>" << endl
                 << "|-------------------------------------------------------------------|" << endl;
        }
    }
    //********************************************************************************************
    cout << "| the total fee:\t\t | " << fee[i] << " Pounds" << endl
         << "|-------------------------------------------------------------------|" << endl;
    cout << "|*******************************************************************|" << endl << endl;
}
void subscriber::search()
{
    string search_sub = "0", choose2 = "0"; long int check_id = 0;
new_e:
    cout << "Please enter the (ID,name,phone,email) of the subscriber you are search: " << endl;
Error_search:
    int error = 0;
    getline(cin, search_sub);
    for (int j = 0; j < search_sub.length(); j++)
    {
        search_sub[j] = tolower(search_sub[j]);
    }
    check_id = conv_str_int(1, search_sub);
    system("color E");
    for (int i = 0; i < 50; i++)
    {
        //***********************************check ID/name/phone/email**********************************************************
        if (!name[i].compare(search_sub) || !phone[i].compare(search_sub) || !email[i].compare(search_sub))
        {
            print(i);
        }
        else if (check_id != 0)
        {
            if (id[i] == check_id)
            {
                print(i);
            }
            else
            {
                error++;
            }
        }
        //***********************************check error*********************************************************************
        else
        {
            error++;
        }
    }
    //***********************************error***************************************************************************
    if (error == 50)
    {
        system("color 04");
        cout << "Error ==> Search result not found try again" << endl;
        goto Error_search;
    }
    //***********************************if you want to search other subscriber:*****************************************
    cout << "if you want to search other subscriber:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
err:
    getline(cin, choose2);
    system("color E");
    //***********************************yes**********************************
    if (choose2 == "1")
    {
        goto new_e;
    }
    //***********************************no**********************************
    else if (choose2 == "2")
    {
        cout << "its don" << endl;
    }
    //***********************************error**********************************
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto err;
    }
}
void subscriber::edit()
{
new_sub:
    string  choose, new_edit; string choose2 = "0", choose3 = "0"; int error = 0; long int check_id = 0; string edit_sub = "0";
        cout << "Please enter the (ID,name,phone,email) of the subscriber you are editing:" << endl;
    Error_search:
        error = 0;
        getline(cin, edit_sub);
        //small letters:
        for (int j = 0; j < edit_sub.length(); j++)
        {
            edit_sub[j] = tolower(edit_sub[j]);
        }
        system("color E");
        check_id = conv_str_int(1, edit_sub);
    for (int i = 0; i < 50; i++)
    {
        //**********************************check ID/name/phone/email******************************************************
        if (id[i] == check_id || !name[i].compare(edit_sub) || !phone[i].compare(edit_sub) || !email[i].compare(edit_sub))
        {
            if (id[i] != 0)
            {
                choose = "6";
            new_ee:
                    cout << "What do you need to edit in this subscriber" << endl;
                    cout << "1-type" << endl;
                    cout << "2-name" << endl;
                    cout << "3-address" << endl;
                    cout << "4-phone" << endl;
                    cout << "5-email" << endl;
                try_again1:
                    getline(cin, choose);
                    system("color E");
                //*******************edit type:*******************************
                if (choose == "1")
                {
                    cout << "please enter the new type" << endl;
                try_again2:
                    getline(cin, type[i]);
                    for (int j = 0; j < type[i].length(); j++)
                    {
                        type[i][j] = tolower(type[i][j]);
                    }
                    system("color E");
                    if (type[i] != "normal" && type[i] != "golden")
                    {
                        system("color 04");
                        cout << "Error ==> Please enter a true type==>ex( Normal or Golden)" << endl;
                        goto try_again2;
                    }
                }
                //*******************edit name:*******************************
                else if (choose == "2")
                {
                    cout << "please enter the new name" << endl;
                    getline(cin, name[i]);
                    for (int j = 0; j < name[i].length(); j++)
                    {
                        name[i][j] = tolower(name[i][j]);
                    }
                }
                //*******************edit address:****************************
                else if (choose == "3")
                {
                    cout << "please enter the new address" << endl;
                    getline(cin, address[i]);
                    for (int j = 0; j < address[i].length(); j++)
                    {
                        address[i][j] = tolower(address[i][j]);
                    }
                }
                //*******************edit phone:******************************
                else if (choose == "4")
                {
                    cout << "please enter the new phone" << endl;
                error_phone:
                    getline(cin, phone[i]);
                    system("color E");
                    if ((!phone[i].compare(0, 3, "010") || !phone[i].compare(0, 3, "011") || !phone[i].compare(0, 3, "012") || !phone[i].compare(0, 3, "015")) && phone[i].length() == 11)
                    {

                    }
                    else
                    {
                        system("color 04");
                        cout << "Error==> please enter a true phone start(010/011/012/015)and length=11" << endl;
                        goto error_phone;
                    }
                }
                //*******************edit email:******************************
                else if (choose == "5")
                {
                    cout << "please enter the new email" << endl;
                err_email:
                    getline(cin, email[i]);
                    system("color E");
                    if (email[i].length() > 14)
                    {
                        for (int j = email[i].length() - 13; j < email[i].length() - 7; j++)
                        {
                            email[i][j] = tolower(email[i][j]);
                        }
                        if (!email[i].compare(email[i].length() - 14, email[i].length(), "@fayoum.edu.eg"))
                        {

                        }
                        else
                        {
                            system("color 04");
                            cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                            goto err_email;
                        }
                    }
                    else
                    {
                        system("color 04");
                        cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                        goto err_email;
                    }
                }
                //*******************Error:***********************************
                else
                {
                    system("color 04");
                    cout << "Error ==> try again enter 1 or 2 or 3 or 4 or 5 or 6 or 7" << endl;
                    goto try_again1;
                }
                //*******************if you want to edit anything other in this subscriber:***************************
                    cout << "if you want to edit anything other in this subscriber:" << endl;
                    cout << "1-yes" << endl;
                    cout << "2-no" << endl;
                err:
                    getline(cin, choose2);
                    system("color E");
                    //************************yes*******************************
                    if (choose2 == "1")
                    {
                        goto new_ee;
                    }
                    //************************no********************************
                    else if (choose2 == "2")
                    {
                        cout << "its don" << endl;
                        break;
                    }
                    //************************error*****************************
                    else
                    {
                        system("color 04");
                        cout << "Error ==>please enter a true choose:" << endl;
                        goto err;
                    }
            }
            else
            {
                error++;
            }
        }
        //**********************************check error*****************************************************************
        else
        {
            error++;
        }

    }
    //**********************************error***********************************************************************
        if (error == 50)
        {
            system("color 04");
            cout << "Error ==>  result not found try again" << endl;
            goto Error_search;
        }
    //************************if you want to edit other subscriber:*************************************************
        cout << "if you want to edit other subscriber:" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
    error_e:
        getline(cin, choose3);
        system("color E");
        if (choose3 == "1")
        {
            goto new_sub;
        }
        else if (choose3 == "2")
        {
            cout << "its don" << endl;
        }
        else
        {
            system("color 04");
            cout << "Error ==>please enter a true choose:" << endl;
            goto error_e;
        }
}
void subscriber::add()
{
new_add:
    int v = 0; string choose2 = "0"; int index = 0;
    for (int i = 0; i < 50; i++)
    {
        //**********************************************Search for an empty place in the storage space**********************************************
        if (!type[i].compare("0") && !name[i].compare("0") && !address[i].compare("0") && !phone[i].compare("0") && !email[i].compare("0"))
        {
            //***************************ID:*******************************************
            id[i] = i + 1; index = i;
            //***************************type:*****************************************
            cout << "enter the type:" << endl;
        try_again1:
            getline(cin, type[i]);
            for (int j = 0; j < type[i].length(); j++)
            {
                type[i][j] = tolower(type[i][j]);
            }
            system("color E");
            if (type[i] != "normal" && type[i] != "golden")
            {
                system("color 04");
                cout << "Error ==> Please enter a true type==>ex( Normal or Golden)" << endl;
                goto try_again1;
            }
            //***************************name:******************************************
            cout << "enter the name:" << endl;
            getline(cin, name[i]);
            for (int j = 0; j < name[i].length(); j++)
            {
                name[i][j] = tolower(name[i][j]);
            }
            //***************************address:***************************************
            cout << "enter address:" << endl;
            getline(cin, address[i]);
            for (int j = 0; j < address[i].length(); j++)
            {
                address[i][j] = tolower(address[i][j]);
            }
            //***************************phone:*****************************************
            cout << "enter phone:" << endl;
        error_phone:
            getline(cin, phone[i]);
            system("color E");
            if ((!phone[i].compare(0, 3, "010") || !phone[i].compare(0, 3, "011") || !phone[i].compare(0, 3, "012") || !phone[i].compare(0, 3, "015")) && phone[i].length() == 11)
            {

            }
            else
            {
                system("color 04");
                cout << "Error==> please enter a true phone start(010/011/012/015)and length=11" << endl;
                goto error_phone;
            }
            //***************************email:*****************************************
            cout << "enter email:" << endl;
        err_email:
            getline(cin, email[i]);
            system("color E");
            if (email[i].length() > 14)
            {
                for (int j = email[i].length() - 13; j < email[i].length() - 7; j++)
                {
                    email[i][j] = tolower(email[i][j]);
                }
                if (!email[i].compare(email[i].length() - 14, email[i].length(), "@fayoum.edu.eg"))
                {

                }
                else
                {
                    system("color 04");
                    cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                    goto err_email;
                }
            }
            else
            {
                system("color 04");
                cout << "Error==> Please enter a true email ex:(am@fayoum.edu.eg)" << endl;
                goto err_email;
            }
            break;
        }
        //***************************check error:********************************
        else
        {
            v++;
        }
    }
    ////***************************error:************************************
    if (v == 50)
    {
        system("cls");
        cout << endl << endl;
        cout << "Unfortunately, the space is full and nothing can be added" << endl << endl << endl;
    }
    for (int j = 0; j < index; j++)
    {
        if (!type[index].compare(type[j]) && !name[index].compare(name[j]) && !address[index].compare(address[j]) && !phone[index].compare(phone[j]) && !email[index].compare(email[j]))
        {
            cout << endl;
            cout << "\tThis data is already there" << endl << endl;
            id[index] = 0;  type[index] = "0"; name[index] = "0"; address[index] = "0"; phone[index] = "0"; email[index] = "0";
        }
    }
    cout << "if you want to add other subscriber:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
err:
    getline(cin, choose2);
    system("color E");
    if (choose2 == "1")
    {
        goto new_add;
    }
    else if (choose2 == "2")
    {
        cout << "its don" << endl;
    }
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto err;
    }
    //***************************************************************
}
void subscriber::borrow(int err_book)
{
    string name_sub; int error_name = 0;
err_book_i:
    if (err_book != 1)
    {
        cout << "Please enter the name of the subscriber who wants to borrow the book" << endl;
        getline(cin, name_sub);
        system("color E");
    }
    for (int i = 0; i < 50; i++)
    {
        if (borrowed_items[i] == "")
        {
            if (!name[i].compare(name_sub) || err_book == 1)
            {
                cout << "Name borrowed book:" << endl;
                getline(cin, borrowed_items[i]);
                for (int j = 0; j < borrowed_items[i].length(); j++)
                {
                    borrowed_items[i][j] = tolower(borrowed_items[i][j]);
                }
                system("color E");
                borrowered = borrowed_items[i];
                break;
            }
            else
            {
                error_name++;
            }
        }
        else
        {
            cout << endl;
            cout << "You have borrowed a book before, you must return it first" << endl << endl;
            break;
        }
    }
    if (error_name == 50 && err_book != 1)
    {
        system("color 04");
        cout << "Error==>This name not found try again:" << endl;
        error_name = 0;
        goto err_book_i;
    }
    err_book = 0;
}
int subscriber::return_borrowed_item(int t)
{
    string name_sub; int error_name = 0; static int index = 0;
    if (t != 1)
    {
    err_book:
        cout << "Please enter the name of the subscriber who wants to return borrowed the book:" << endl;
        getline(cin, name_sub);
        system("color E");
        for (int i = 0; i < 50; i++)
        {
                if (!name[i].compare(name_sub))
                {
                    if (borrowed_items[i] != "")
                    {
                        index = i;
                        cout << "Name the book borrowed: '" << borrowed_items[i] << "'" << endl;
                        borrowered = borrowed_items[i];
                        break;
                    }
                    else
                    {
                        borrowered = borrowed_items[i];
                        cout << endl;
                        cout << "You haven't borrowed books yet" << endl << endl;
                        break;
                    }
                }
                else
                {
                    error_name++;
                }
        }
        if (error_name == 50)
        {
            system("color 04");
            cout << "Error==>This name not found (try again):" << endl;
            error_name = 0;
            goto err_book;
        }
    }

    if (t == 1)
    {
        //***************************time:******************************************
        cout << "Please enter the time:" << endl;
        time[index] = conv_str_int(0, "0");
        //**********************
        if (type[index] == "normal")
        {
            //three weeks:
            if (time[index] > 21)
            {
                fee[index] = (time[index] - (21)) * 2;//Fee 2 pounds for each day of delay
            }
            else
            {
                fee[index] = 0;
            }
        }
        else if (type[index] == "golden")
        {
            //three months:
            if (time[index] > 90)
            {
                fee[index] = (time[index] - (90)) * 2;//Fee 2 pounds for each day of delay
            }
            else
            {
                fee[index] = 0;
            }
        }
        cout << "the total fee: '" << fee[index] << "' Pounds" << endl;
        //**********************
    }
    return index;
}
void subscriber::payment()
{
    string name_sub; int error_name = 0;  int amount_paid = 0, index = 0,delay=0;
err_book:
    cout << "Please enter the subscriber's name:" << endl;
    getline(cin, name_sub);
    system("color E");
    for (int i = 0; i < 50; i++)
    {
        if (!name[i].compare(name_sub))
        {
            if (borrowed_items[i] == "")
            {
                cout << "the total borrowered time is: '" << time[i] << "' days" << endl;
                if (type[i] == "normal")
                {
                    index = i;
                    //three weeks:
                    if (time[i] > 21)
                    {
                        fee[i] = (time[i] - (21)) * 2;//Fee 2 pounds for each day of delay
                        cout << "The delay period: '" << time[i] - 21 << "' days" << endl;
                        delay = 21;
                    }
                    else
                    {
                        fee[i] = 0;
                        cout << "The delay period: " << "<There is no delay>" << endl;
                    }
                }
                else if (type[i] == "golden")
                {
                    //three months:
                    if (time[i] > 90)
                    {
                        fee[i] = (time[i] - (90)) * 2;//Fee 2 pounds for each day of delay
                        cout << "The delay period: '" << time[i] - 90 << "' days" << endl;
                        delay = 90;
                    }
                    else
                    {
                        fee[i] = 0;
                        cout << "The delay period: " << "<There is no delay>" << endl;
                    }
                }
                cout << "the total fee: '" << fee[i] << "' Pounds" << endl;
                break;
            }
        }
        else
        {
            error_name++;
        }

    }
    if (error_name == 50)
    {
        system("color 04");
        cout << "Error==>This name not found (try again):" << endl;
        error_name = 0;
        goto err_book;
    }
    if (borrowed_items[index] == "")
    {
        if (fee[index] != 0)
        {
            cout << "please enter the amount paid:" << endl;
            am:
            amount_paid = conv_str_int(0, "0");
            if (amount_paid<1)
            {
                system("color 04");
                cout << "Error==> The amount paid must be greater than zero" << endl;
                goto am;
            }
            cout << "The amount paid:" << amount_paid << endl;

            if ((amount_paid - fee[index]) > 0)
            {
                cout << "Your remaining amount:" << amount_paid - fee[index] << endl;
                time[index] = 0;
                fee[index] = 0;
            }
            else if ((amount_paid - fee[index]) < 0)
            {
                cout << "The remaining amount for you:" << fee[index] - amount_paid << endl;
                time[index] = (amount_paid / 2) + delay;
                fee[index] = (fee[index] - amount_paid);
            }
            else
            {
                time[index] = 0;
                fee[index] = 0;
            }
        }
    }
    else
    {
        cout << "\t<The book must first be returned>" << endl;
    }
}
void subscriber::_delete(int del_ret_b, int index)
{
    if (del_ret_b == 1)
    {
        borrowed_items[index] = "";
    }
    if (del_ret_b != 1)
    {
    new_e:
        string delete_sub = "0"; string choose2 = "0"; long int check_id = 0;
        cout << "Please enter the (ID,name,phone,email) of subscriber you are delete" << endl;
    t_again:
        int xx = 0;
        getline(cin, delete_sub);
        for (int j = 0; j < delete_sub.length(); j++)
        {
            delete_sub[j] = tolower(delete_sub[j]);
        }
        system("color E");
        check_id = conv_str_int(1, delete_sub);
        for (int i = 0; i < 50; i++)
        {
            //****************************************check ID/name/phone/email*******************************************************
            if (id[i] == check_id || !name[i].compare(delete_sub) || !phone[i].compare(delete_sub) || !email[i].compare(delete_sub))
            {
                if (id[i] != 0)
                {
                    id[i] = 0;
                    type[i] = "0";
                    name[i] = "0";
                    address[i] = "0";
                    phone[i] = "0";
                    email[i] = "0";
                    borrowed_items[i] = "0";
                    time[i] = 0;
                    fee[i] = 0;
                    xx = 1;
                }
            }
        }
        //****************************************error************************************************************************
        if (xx == 0)
        {
            system("color 04");
            cout << "Error ==>This name not found try again" << endl;
            goto t_again;
        }
        //****************************************if you want to delete other subscriber:**************************************
        xx = 0;
        cout << "if you want to delete other subscriber:" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
    err:
        getline(cin, choose2);
        system("color E");
        //***********************yes***********************************
        if (choose2 == "1")
        {
            goto new_e;
        }
        //***********************no************************************
        else if (choose2 == "2")
        {
            cout << "its don" << endl;
        }
        //***********************error*********************************
        else
        {
            system("color 04");
            cout << "Error ==>please enter a true choose:" << endl;
            goto err;
        }
    }
}
void subscriber::print_reports()
{
    for (int i = 0; i < 50; i++)
    {
        //************Print normal/golden subscriber whose borrowed period has ended************
        if ((type[i] == "normal" && time[i] > 21)|| (type[i] == "golden" && time[i] > 90))
        {
            print(i);
        }
        else
        {
            cout << endl;
            cout << "\tThere are no late borrowed items" << endl << endl;
            break;
        }
    }
}
//*************************************************************

//outside class contents:
//*************************************************************
contents::contents()
{
    for (int i = 0; i < 120; i++)
    {
        //Item_ID[i] = 0;
        Category[i] = "0";
        Title[i] = "0";
        Author[i] = "0";
        Publisher[i] = "0";
        Production_Year[i] = 0;
        Status[i] = "0";
        Copies[i] = 0;
    }

}
long int contents::conv_str_int(int tc, string ID)
{
    long int int_var = 0;
a:
    int_var = 0;
    string str = "0";
    long int y[4] = { 0 }, b = 0, j = 0;
    if (tc != 3)
    {
        getline(cin, str);
    }
    if (tc == 3)
    {
        str = ID;
        if (str.length() > 3)
        {
            b = 2;
        }

    }
    system("color E");
    if (b != 2)
    {
        if (str.length() > 4)
        {
            system("color 04");
            cout << "Error==> please enter a true value(int & 4 bit):" << endl;
            goto a;
        }
        j = str.length() - 1;
        for (int s = 0; s < str.length(); s++)
        {
            y[s] = str[j];

            if (y[s] < 48 || y[s]>57)
            {
                b = 1;
            }
            else
            {
                y[s] = y[s] - 48;
            }
            j--;
        }
        int malt = 1;
        if (b == 1)
        {
            system("color 04");
            cout << "Error==> please enter a true value(int & 4 bit):" << endl;
            goto a;
        }
        for (int s = 0; s < str.length(); s++)
        {
            y[s] = y[s] * malt;

            malt = malt * 10;
            int_var += y[s];
        }

        if (tc == 1)
        {
            if (int_var > 2021)
            {
                system("color 04");
                cout << "Error==>please enter a true value(int & 4 bit):" << endl;
                goto a;
            }
        }
        if (tc == 2)
        {
            if (int_var > 50)
            {
                system("color 04");
                cout << "Error==>please enter a true value(int & 4 bit):" << endl;
                goto a;
            }
        }
    }
    return int_var;
}
void contents::print_sections(int start, int end)
{
    cout << "----------------------------------------------------------------------------------------" << endl;
    for (int i = start; i < end; i++)
    {
        if (Title[i] != "0")
        {
            cout << Item_ID[i] << "-";
            cout << Title[i] << endl;
        }
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
}
void contents::edit(int start, int end)
{
t_again2:
    int v = 0; long int check_id = 0;
    string choose = "0", new_edit = "0", choose2 = "0", edit_book = "0", choose3 = "0";
    cout << "Please enter the (ID/Title/Author/Publisher) of the book you are edit" << endl;
    getline(cin, edit_book);
    system("color E");
    check_id = conv_str_int(3, edit_book);
    for (int i = start; i < end; i++)
    {
        //******************************************check ID/Title/Author/Publisher******************************************
        if (Item_ID[i] == check_id || !Title[i].compare(edit_book) || !Author[i].compare(edit_book) || !Publisher[i].compare(edit_book))
        {
            if (Item_ID[i] != 0)
            {
            new_e:
                cout << "What do you need to edit in this book" << endl;
                cout << "1-Category" << endl;
                cout << "2-title" << endl;
                cout << "3-auther" << endl;
                cout << "4-publisher" << endl;
                cout << "5-production Year" << endl;
                cout << "6-status" << endl;
                cout << "7-copies" << endl;
            try_again1:
                getline(cin, choose);
                system("color E");
                //*********************Category*******************************
                if (choose == "1")
                {
                    cout << "please enter the new Category" << endl;
                err_cat:
                    getline(cin, Category[i]);
                    system("color E");
                    for (int j = 0; j < Category[i].length(); j++)
                    {
                        Category[i][j] = tolower(Category[i][j]);
                    }
                    if (!Category[i].compare("book") || !Category[i].compare("article in a journal") || !Category[i].compare("digital media"))
                    {

                    }
                    else
                    {
                        system("color 04");
                        cout << "Error==> Please enter a true Category:(book,article in a journal,digital media):" << endl;
                        goto err_cat;
                    }
                }
                //*********************title**********************************
                else if (choose == "2")
                {
                    cout << "please enter the new title" << endl;
                    getline(cin, Title[i]);
                    for (int j = 0; j < Title[i].length(); j++)
                    {
                        Title[i][j] = tolower(Title[i][j]);
                    }
                }
                //*********************auther*********************************
                else if (choose == "3")
                {
                    cout << "please enter the new auther" << endl;
                    getline(cin, Author[i]);
                    for (int j = 0; j < Author[i].length(); j++)
                    {
                        Author[i][j] = tolower(Author[i][j]);
                    }
                }
                //*********************publisher******************************
                else if (choose == "4")
                {
                    cout << "please enter the new publisher" << endl;
                    getline(cin, Publisher[i]);
                    for (int j = 0; j < Publisher[i].length(); j++)
                    {
                        Publisher[i][j] = tolower(Publisher[i][j]);
                    }
                }
                //*********************production Year************************
                else if (choose == "5")
                {
                    cout << "please enter the new production Year" << endl;
                    Production_Year[i] = conv_str_int(1, "0");
                }
                //*********************status*********************************
                else if (choose == "6")
                {
                    cout << "please enter the new status" << endl;
                err_st:
                    getline(cin, Status[i]);
                    system("color e");
                    for (int j = 0; j < Status[i].length(); j++)
                    {
                        Status[i][j] = tolower(Status[i][j]);
                    }
                    if (Status[i] != "on shelf" || Status[i] != "on the site")
                    {
                        system("color 04");
                        cout << "Error==> Please enter a true Status ex:(on shelf,on the site)" << endl;
                        goto err_st;
                    }
                }
                //*********************copies*********************************
                else if (choose == "7")
                {
                    cout << "please enter the new copies" << endl;
                    Copies[i] = conv_str_int(2, "0");
                }
                //*********************error**********************************
                else
                {
                    system("color 04");
                    cout << "Error ==> try again enter 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 " << endl;
                    goto try_again1;
                }
                //***************************if you want to edit anything other in this book:******************
                cout << "if you want to edit anything other in this book:" << endl;
                cout << "1-yes" << endl;
                cout << "2-no" << endl;
            err:
                getline(cin, choose2);
                system("color E");
                //***************************yes*************************
                if (choose2 == "1")
                {
                    goto new_e;
                }
                //***************************no**************************
                else if (choose2 == "2")
                {
                    cout << "its don" << endl;
                }
                //***************************error***********************
                else
                {
                    system("color 04");
                    cout << "Error ==>please enter a true choose:" << endl;
                    goto err;
                }
            }
            else
            {
                v++;
            }
        }
        //***************************check error*****************
        else
        {
            v++;
        }
    }
    //***************************error***********************
    if (v == 20)
    {
        system("color 04");
        cout << "Error ==> this book not found try again" << endl;
        v = 0;
        goto t_again2;
    }
    //***************************if you want to edit other book:***************************
    cout << "if you want to edit other book:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
error:
    getline(cin, choose3);
    system("color E");
    //***************************yes*************************
    if (choose3 == "1")
    {
        goto  t_again2;
    }
    //***************************no**************************
    else if (choose3 == "2")
    {
        cout << "its don" << endl;
    }
    //***************************error***********************
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto error;
    }
}
void contents::_delete(int start, int end, int dele, int j)
{
    //*******************(delete book if copies=0)**********************
    if (dele == 1)
    {
        Item_ID[j] = 0;
        Category[j] = "0";
        Title[j] = "0";
        Author[j] = "0";
        Publisher[j] = "0";
        Production_Year[j] = 0;
        Status[j] = "0";
        Copies[j] = 0;
    }

    if (dele != 1)
    {
    new_e:
        string delete_book = "0";  int xx = 0; string choose2 = "0"; long int check_id = 0;
        cout << "Please enter the (ID,Title/Author/Publisher) of the book you are delete" << endl;
    t_again:
        getline(cin, delete_book);
        for (int j = 0; j < delete_book.length(); j++)
        {
            delete_book[j] = tolower(delete_book[j]);
        }
        system("color E");
        check_id = conv_str_int(3, delete_book);
        for (int i = start; i < end; i++)
        {
            //******************************************check ID/Title/Author/Publisher******************************************
            if (Item_ID[i] == check_id || !Title[i].compare(delete_book) || !Author[i].compare(delete_book) || !Publisher[i].compare(delete_book))
            {
                if (Item_ID[i] != 0)
                {
                    Item_ID[i] = 0;
                    Category[i] = "0";
                    Title[i] = "0";
                    Author[i] = "0";
                    Publisher[i] = "0";
                    Production_Year[i] = 0;
                    Status[i] = "0";
                    Copies[i] = 0;
                    xx = 1;
                }
            }

        }
        //*****************************************error******************************************************************
        if (xx == 0)
        {
            system("color 04");
            cout << "Error ==>This name not found try again" << endl;
            goto t_again;
        }
        xx = 0;
        //*****************************************if you want to delete other book:**************************************
        cout << "if you want to delete other book:" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
    err:
        getline(cin, choose2);
        system("color E");
        //*****************************yes*******************************
        if (choose2 == "1")
        {
            goto new_e;
        }
        //*****************************no********************************
        else if (choose2 == "2")
        {
            cout << "its don" << endl;
        }
        //*****************************error*****************************
        else
        {
            system("color 04");
            cout << "Error ==>please enter a true choose:" << endl;
            goto err;
        }
    }
}
void contents::search(int start, int end)
{
new_e:
    string General_search = "0", choose2 = "0"; long int check_id = 0;
    int xx = 0;
    cout << "Please enter the (ID,Title,Author,Publisher) of the book you are search: " << endl;
error_search:
    getline(cin, General_search);
    for (int j = 0; j < General_search.length(); j++)
    {
        General_search[j] = tolower(General_search[j]);
    }
    system("color E");
    check_id = conv_str_int(3, General_search);
    for (int i = start; i < end; i++)
    {
        //******************************************check ID/Title/Author/Publisher******************************************
        if (Item_ID[i] == check_id || !Title[i].compare(General_search) || !Author[i].compare(General_search) || !Publisher[i].compare(General_search))
        {
            if (Item_ID[i] != 0)
            {
                cout << endl;
                cout << "Item_ID         ==> " << Item_ID[i] << endl;
                cout << "Category        ==> " << Category[i] << endl;
                cout << "Title           ==> " << Title[i] << endl;
                cout << "Author          ==> " << Author[i] << endl;
                cout << "Publisher       ==> " << Publisher[i] << endl;
                cout << "Production_Year ==> " << Production_Year[i] << endl;
                cout << "Status          ==> " << Status[i] << endl;
                cout << "Copies          ==> " << Copies[i] << endl << endl;
                xx = 1;
            }
        }
    }
    //******************************************error******************************************************************
    if (xx == 0)
    {
        system("color 04");
        cout << "Error ==> Search result not found try again" << endl;
        goto error_search;
    }
    xx = 0;
    //******************************************if you want to search anything other in this section:******************
    cout << "if you want to search anything other in this section:" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
err:
    getline(cin, choose2);
    system("color E");
    //*****************************yes**********************
    if (choose2 == "1")
    {
        goto new_e;
    }
    //*****************************no***********************
    else if (choose2 == "2")
    {
        cout << "its don" << endl;
    }
    //*****************************error********************
    else
    {
        system("color 04");
        cout << "Error ==>please enter a true choose:" << endl;
        goto err;
    }

}
void contents::add(int start, int end, int old_book)
{

new_e:
    int v = 0; string  choose2 = "0";
    if (old_book == 0)
    {
        for (int i = start; i < end; i++)
        {
            //**********************************************Search for an empty place in the storage space**********************************************
            if (!Category[i].compare("0") && !Title[i].compare("0") && !Author[i].compare("0") && !Publisher[i].compare("0"))
            {
                //***********************************ID*************************************
                Item_ID[i] = (i + 1); indx = i;
                //***********************************Category*******************************
                cout << "enter the Category:" << endl;
            err_cat:
                getline(cin, Category[i]);
                system("color E");
                for (int j = 0; j < Category[i].length(); j++)
                {
                    Category[i][j] = tolower(Category[i][j]);
                }
                if (!Category[i].compare("book") || !Category[i].compare("article in a journal") || !Category[i].compare("digital media"))
                {

                }
                else
                {
                    system("color 04");
                    cout << "Error==> Please enter a true Category:(book,article in a journal,digital media):" << endl;
                    goto err_cat;
                }
                //************************************title*********************************
                cout << "enter the title:" << endl;
                getline(cin, Title[i]);
                for (int j = 0; j < Title[i].length(); j++)
                {
                    Title[i][j] = tolower(Title[i][j]);
                }
                //************************************auther*********************************
                cout << "enter the auther:" << endl;
                getline(cin, Author[i]);
                for (int j = 0; j < Author[i].length(); j++)
                {
                    Author[i][j] = tolower(Author[i][j]);
                }
                //************************************publisher******************************
                cout << "enter the publisher:" << endl;
                getline(cin, Publisher[i]);
                for (int j = 0; j < Publisher[i].length(); j++)
                {
                    Publisher[i][j] = tolower(Publisher[i][j]);
                }
                //************************************Production Year************************
                cout << "enter the Production Year:" << endl;
                Production_Year[i] = conv_str_int(1, "0");
                //************************************ststus*********************************
                cout << "enter the ststus:" << endl;
            err_st:
                getline(cin, Status[i]);
                system("color e");
                for (int j = 0; j < Status[i].length(); j++)
                {
                    Status[i][j] = tolower(Status[i][j]);
                }
                if (!Status[i].compare("on shelf") || !Status[i].compare("on the site"))
                {

                }
                else
                {
                    system("color 04");
                    cout << "Error==> Please enter a true Status ex:(on shelf,on the site)" << endl;
                    goto err_st;
                }
                //************************************copies*********************************
                cout << "enter the copies:" << endl;
                Copies[i] = conv_str_int(2, "0");
                break;
            }
            //************************************check error*****************************
            else
            {
                v++;
            }
        }
        //************************************error***********************************
        if (v == 20)
        {
            system("cls");
            cout << endl << endl;
            cout << "Unfortunately, the space is full and nothing can be added in this section" << endl << endl << endl;
            v = 0;
        }
    }
    if (old_book == 1)
    {
        //************************************if you want to add other book:**********
        cout << "if you want to add other book:" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
    err:
        getline(cin, choose2);
        system("color E");
        //*******************yes****************************
        if (choose2 == "1")
        {
            old_book = 0;
            er_ad = 1;
            goto new_e;
        }
        //*******************no*****************************
        else if (choose2 == "2")
        {
            er_ad = 0;
            cout << "its don" << endl;
        }
        //*******************error**************************
        else
        {
            system("color 04");
            cout << "Error ==>please enter a true choose:" << endl;
            goto err;
        }
    }
}
void contents::interface()
{
    cout << "Any section in the library you want:" << endl;
    cout << "1-Arts_and_Architecture" << endl;
    cout << "2-Computer_Science_and_Engineering" << endl;
    cout << "3-Business_and_Economics" << endl;
    cout << "4-Science_and_Mathematics" << endl;
    cout << "5-Education" << endl;
    cout << "6-General_and_News" << endl;
    cout << "please enter 1 or 2 or 3 or 4 or 5 or 6" << endl;
}
/*string contents::get()
{
    for (int i = 0; i < 100; i++)
    {
        &Title[i]; &Author[i]; &Publisher[i], & Production_Year[i], & Status[i], & Copies[i];
    }
    return Title[0];
}
*/
//*************************************************************
//outside class Arts_and_Architecture:
//*************************************************************
Arts_and_Architecture::Arts_and_Architecture()
{
    //book:
    Item_ID[0] = 1; Category[0] = "book";   Title[0] = "things i learned in architecture school 101"; Author[0] = "matthew frederick"; Publisher[0] = "alan plattus"; Production_Year[0] = 1998; Status[0] = "on shelf"; Copies[0] = 5;

    Item_ID[1] = 2; Category[1] = "book";  Title[1] = "building types";                              Author[1] = "joseph chiara";    Publisher[1] = "michael j.crosbie"; Production_Year[1] = 1995; Status[1] = "on shelf"; Copies[1] = 3;

    Item_ID[2] = 3; Category[2] = "book";  Title[2] = "architectural design data";                   Author[2] = "donold watson";    Publisher[2] = "the mcgraw-hill companies,inc"; Production_Year[2] = 1999; Status[2] = "on shelf"; Copies[2] = 2;

    Item_ID[3] = 4; Category[3] = "book"; Title[3] = "interior design";                             Author[3] = "joseph chiara";    Publisher[3] = "julius panero"; Production_Year[3] = 1986; Status[3] = "on shelf"; Copies[3] = 1;

    Item_ID[4] = 5; Category[4] = "book"; Title[4] = "landscape architecture";                      Author[4] = "charles w.harris"; Publisher[4] = "nicholas t.dines"; Production_Year[4] = 1989; Status[4] = "on shelf"; Copies[4] = 1;

    Item_ID[5] = 6; Category[5] = "book"; Title[5] = "urban design";                                Author[5] = "donold watson";    Publisher[5] = "alan plattus"; Production_Year[5] = 1997; Status[5] = "on shelf"; Copies[5] = 2;

    Item_ID[6] = 7; Category[6] = "book"; Title[6] = "site construction details";                   Author[6] = "nicholas denise";  Publisher[6] = "kyle d.brown"; Production_Year[6] = 1990; Status[6] = "on shelf"; Copies[6] = 4;

    //article in a journal:
    Item_ID[7] = 8; Category[7] = "article in a journal"; Title[7] = "pencil sketching";                            Author[7] = "journal of art and architecture studies"; Publisher[7] = "scienceline"; Production_Year[7] = 2020; Status[7] = "on shelf"; Copies[7] = 5;

    //digital media:
    Item_ID[8] = 9; Category[8] = "digital media"; Title[8] = "how media architecture is reshaping the future of workplace design"; Author[8] = "emily webster";  Publisher[8] = "erynn patrick"; Production_Year[8] = 2019; Status[8] = "on the site"; Copies[8] = 1;

    //index==> 0:19 && empty==> 9:19 //Item_ID==> 1:20
}
//*************************************************************
//outside class Computer_Science_and_Engineering:
//*************************************************************
Computer_Science_and_Engineering::Computer_Science_and_Engineering()
{
    //book:
    Item_ID[20] = 21; Category[20] = "book"; Title[20] = "software & technology"; Author[20] = "hani atta"; Publisher[20] = "computing"; Production_Year[20] = 2006; Status[20] = "on shelf"; Copies[20] = 4;

    Item_ID[21] = 22; Category[21] = "book"; Title[21] = "introduction to computer science"; Author[21] = "muhammad yenhan"; Publisher[21] = "the egyptian house"; Production_Year[21] = 2001; Status[21] = "on shelf"; Copies[21] = 10;

    Item_ID[22] = 23; Category[22] = "book"; Title[22] = "skills & applications skills"; Author[22] = "ibrahim abdullah"; Publisher[22] = " el suwa"; Production_Year[22] = 1990; Status[22] = "on shelf"; Copies[22] = 3;

    Item_ID[23] = 24; Category[23] = "book"; Title[23] = "architects data"; Author[23] = "emsp neufert"; Publisher[23] = "ibn etheyeh"; Production_Year[23] = 1880; Status[23] = "on shelf"; Copies[23] = 5;

    Item_ID[24] = 25; Category[24] = "book"; Title[24] = "introduction to computer science"; Author[24] = "michael d.ciletti"; Publisher[24] = "m.morris mano"; Production_Year[24] = 2000; Status[24] = "on shelf"; Copies[24] = 2;

    Item_ID[25] = 26; Category[25] = "book"; Title[25] = "architects data"; Author[25] = "ahmed mohamed jad allah"; Publisher[25] = "egyptian deer"; Production_Year[25] = 2010; Status[25] = "on shelf"; Copies[25] = 1;

    //article in a journal:
    Item_ID[26] = 27; Category[20] = "article in a journal"; Title[26] = "new model for local fractional integral of chebyshev polynomials for image denoising"; Author[26] = "suzan J obaiys"; Publisher[26] = "hamid a jalab"; Production_Year[26] = 2019; Status[26] = "on shelf"; Copies[26] = 3;

    //digital media:
    Item_ID[27] = 28; Category[27] = "digital media"; Title[27] = "audio-visual data processing"; Author[27] = "abdou youssef"; Publisher[27] = "james hahn"; Production_Year[27] = 2013; Status[27] = "on the site"; Copies[72] = 1;

    //index==>20:39 && empty==>28:39 //Item_ID==> 21:40
}
//*************************************************************
//outside class Business_and_Economics:
//*************************************************************
Business_and_Economics::Business_and_Economics()
{
    //book:
    Item_ID[40] = 41; Category[40] = "book"; Title[40] = "peter derrac"; Author[40] = "john ala fahrati"; Publisher[40] = "harper collins"; Production_Year[40] = 1900; Status[40] = "on shelf"; Copies[40] = 1;
    Item_ID[41] = 42; Category[41] = "book"; Title[41] = "future shock"; Author[41] = "ahmad shawqi"; Publisher[41] = "ibn al-atheer"; Production_Year[41] = 1890; Status[41] = "on shelf"; Copies[41] = 12;
    Item_ID[42] = 43; Category[42] = "book"; Title[42] = "entrepreneur"; Author[42] = " muhammad husam khidr"; Publisher[42] = "al-masah"; Production_Year[42] = 1998; Status[42] = "on shelf"; Copies[42] = 12;

    Item_ID[43] = 44; Category[43] = "book"; Title[43] = "the capitalist system and its future"; Author[43] = "hazem al-beblawy"; Publisher[43] = "al-shorouk"; Production_Year[43] = 1900; Status[43] = "on shelf"; Copies[43] = 12;

    Item_ID[44] = 45; Category[44] = "book"; Title[44] = "principles of business administration"; Author[44] = "hagan"; Publisher[44] = "al-shamimari"; Production_Year[44] = 1902; Status[44] = "on shelf"; Copies[44] = 12;

    //article in a journal:
    Item_ID[45] = 46; Category[45] = "article in a journal"; Title[45] = ""; Author[45] = "the volatility of mutual fund performance"; Publisher[45] = "journal of economics and business"; Production_Year[45] = 2019; Status[45] = "on shelf"; Copies[45] = 2;

    //digital media:
    Item_ID[46] = 47; Category[46] = "digital media"; Title[46] = "new business and economic models in the connected digital economy"; Author[46] = "irene clng"; Publisher[46] = "timothy l.keiningham"; Production_Year[46] = 2014; Status[46] = "on the site"; Copies[46] = 1;

    //index==>40:59 && empty==>47:59 //Item_ID==> 41:60
}
//*************************************************************
//outside class Science_and_Mathematics:
//*************************************************************
Science_and_Mathematics::Science_and_Mathematics()
{
    //book:
    Item_ID[60] = 61; Category[60] = "book"; Title[60] = "science and mathematics for engineering"; Author[60] = "john bird"; Publisher[60] = "routledge"; Production_Year[60] = 2019; Status[60] = "on shelf"; Copies[60] = 2;

    Item_ID[61] = 62; Category[61] = "book"; Title[61] = "science and mathematics in ancient greek culture"; Author[61] = "c.j.tuplin"; Publisher[61] = "t.e.rihll"; Production_Year[61] = 2015; Status[61] = "on shelf"; Copies[61] = 3;

    Item_ID[62] = 63; Category[62] = "book"; Title[62] = "bringing science and mathematics to life for all learners"; Author[62] = "dennis adams"; Publisher[62] = "mary hamm"; Production_Year[62] = 2014; Status[62] = "on shelf"; Copies[2] = 2;

    Item_ID[63] = 64; Category[63] = "book"; Title[63] = "cognitive science and mathematics education"; Author[63] = "alan h.schoenfeld‏"; Publisher[63] = "pollak"; Production_Year[63] = 1913; Status[63] = "on shelf"; Copies[3] = 2;

    Item_ID[64] = 65; Category[64] = "book"; Title[64] = "university science and mathematics education in transition"; Author[64] = "ole skovsmose"; Publisher[64] = "paola valero"; Production_Year[64] = 1914; Status[64] = "on shelf"; Copies[4] = 1;

    //article in a journal:
    Item_ID[65] = 66; Category[65] = "article in a journal"; Title[65] = "introduction to computational science and mathematics"; Author[65] = "charles f.van loan"; Publisher[65] = "jones"; Production_Year[65] = 1985; Status[65] = "on shelf"; Copies[5] = 1;

    //digital media:
    Item_ID[66] = 67; Category[66] = "digital media"; Title[66] = "mathematics of multimedia"; Author[66] = "michael barnsley"; Publisher[66] = "institute for mathematics and its applications"; Production_Year[66] =2000 ; Status[65]="on the site";Copies[65] = 1;

         //index==>60:79 && empty==>67:79 //Item_ID==> 61:80
}
//*************************************************************
//outside class Education:
//*************************************************************
Education::Education()
{
    //book:
    Item_ID[80] = 81; Category[80] = "book"; Title[80] = "learning "; Author[80] = "anwar mohammed"; Publisher[80] = "egyptian house"; Production_Year[80] = 2020; Status[80] = "on shelf"; Copies[80] = 22;

    Item_ID[81] = 82; Category[81] = "book"; Title[81] = " daman el_shamaeh"; Author[81] = "shafair"; Publisher[81] = "useful mum"; Production_Year[81] = 2019; Status[81] = "on shelf"; Copies[81] = 11;

    Item_ID[82] = 83; Category[82] = "book"; Title[82] = "west westview"; Author[82] = "prince zoo"; Publisher[82] = "kindergarten"; Production_Year[82] = 2018; Status[82] = "on shelf"; Copies[82] = 14;

    Item_ID[83] = 84; Category[83] = "book"; Title[83] = "training strategies"; Author[83] = "thouqan obaidat"; Publisher[83] = "al-masah"; Production_Year[83] = 2018; Status[83] = "on shelf"; Copies[83] = 12;

    Item_ID[84] = 85; Category[84] = "book"; Title[84] = "pages in education and advancement in person"; Author[84] = "abdul karim bakar"; Publisher[84] = "safwa"; Production_Year[84] = 2017; Status[84] = "on shelf"; Copies[84] = 13;

    //article in a journal:
    Item_ID[85] = 86; Category[85] = "article in a journal"; Title[85] = " a new decade for social changes"; Author[85] = "said shams"; Publisher[85] = "technium social sciences journal "; Production_Year[85] = 2020; Status[85] = "on shelf"; Copies[85] = 3;

    //digital media:
    Item_ID[86] = 87; Category[86] = "digital media"; Title[86] = "education and social media toward a digital future"; Author[86] = "christine greenhow"; Publisher[86] = "colin agur"; Production_Year[86] = 2016; Status[86] = "on the site"; Copies[86] = 4;

    //index==>80:99 && empty==>87:99 //Item_ID==> 81:100
}
//*************************************************************
//outside class General_and_News:
//*************************************************************
General_and_News::General_and_News()
{

    //book:
    Item_ID[100] = 101; Category[100] = "book"; Title[100] = "full in history"; Author[100] = "ezz eldin"; Publisher[100] = "ibn atheer"; Production_Year[100] = 2016; Status[100] = "on shelf"; Copies[100] = 2;

    Item_ID[101] = 102; Category[101] = "book"; Title[101] = "events"; Author[101] = "el asendra"; Publisher[101] = " mankotzio villa"; Production_Year[101] = 2015; Status[101] = "on shelf"; Copies[101] = 3;

    Item_ID[102] = 103; Category[102] = "book"; Title[102] = "insta Life"; Author[102] = "muhammad sadiq"; Publisher[102] = "al-rawaf, year of publication"; Production_Year[102] = 2014; Status[102] = "on shelf"; Copies[102] = 4;

    Item_ID[103] = 104; Category[103] = "book"; Title[103] = "hepta"; Author[103] = "mohammed sadik"; Publisher[103] = " lead"; Production_Year[103] = 1913; Status[103] = "on shelf"; Copies[103] = 5;

    Item_ID[104] = 105; Category[104] = "book"; Title[104] = "millennium in belgrade"; Author[104] = "vladimir bastalo"; Publisher[104] = "hind adel"; Production_Year[104] = 1914; Status[104] = "on shelf"; Copies[104] = 11;

    //article in a journal:
    Item_ID[105] = 106; Category[105] = "article in a journal"; Title[105] = "an estimation of undetected covid"; Author[105] = "jeffrey shaman"; Publisher[105] = "jeff tollefson"; Production_Year[105] = 2020; Status[105] = "on shelf"; Copies[105] = 2;

    //digital media:
    Item_ID[106] = 107; Category[106] = "digital media"; Title[106] = "global epidemic"; Author[106] = "philip ball"; Publisher[106] = "taylor engdahl"; Production_Year[106] = 2020; Status[106] = "on the site"; Copies[106] = 1;

    //index==>100:119 && empty==>107:119 //Item_ID==> 101:120
}
//*************************************************************


int main()
{
   
    //*******************************************
    Library ob_l;
    //*******************************************
    subscriber ob_s;
    string choose_s;
    //*******************************************
    contents ob;
    Arts_and_Architecture ob1;
    Computer_Science_and_Engineering ob2;
    Business_and_Economics ob3;
    Science_and_Mathematics ob4;
    Education ob5;
    General_and_News ob6;
    //*******************************************
    string choose = "0", section1 = "0";
    //*******************************************
                  //interface project:
//**********************************************************************************************
    cout << "      *****welcome*****" << endl;
    cout<<"note this....\nLibrary ID==islam atef\n";
    //interface Library:
    ob_l.set_Library_ID();
    ob_l.set_Name();
    cout << endl;
    cout << "*******************************************************"<< endl;
    cout << "Library ID: " << ob_l.get_Library_ID() << "\t";
    cout << "Name: " << ob_l.get_Name()<<endl;
    cout << "*******************************************************" << endl << endl;
    //********************************************
again_end:
    cout << "1-Subscribers section:" << endl;
    cout << "2-Books section:" << endl;
    cout << "please enter choose (1 or 2):" << endl;
ERR:
    getline(cin, section1);
    system("color E");
    //interface subscriber:
//******************************************************************************************
    if (section1 == "1")
    {
    new_operation_s:
        cout << "1-Search:" << endl;
        cout << "2-Edit:" << endl;
        cout << "3-Add:" << endl;
        cout << "4-Delete:" << endl;
        cout << "5-Borrow items:" << endl;
        cout << "6-Return borrowed item:" << endl;
        cout << "7-Payment:" << endl;
        cout << "8-If you want print reports of overdue borrowed items:" << endl;
    error_s:
        getline(cin, choose_s);
        system("color E");
        //***********************search:*************************
        if (choose_s == "1")
        {
            ob_s.search();
        }
        //***********************edit****************************
        else if (choose_s == "2")
        {
            ob_s.edit();
            
        }
        //***********************add*******************
        else if (choose_s == "3")
        {
            ob_s.add();

        }
        //***********************delete**************************
        else if (choose_s == "4")
        {
            ob_s._delete(0, 0);
        }
        //***********************borrowed************************
        else if (choose_s == "5")
        {
            //**************************************
            string see_book, choose2 = "0";
            //cout << "please enter the name of the book you want to borrow:" << endl;
            cout << "If you want to see books:" << endl;
            cout << "1-yes:" << endl;
            cout << "1-no:" << endl;
        see:
            getline(cin, see_book);
            system("color E");
            if (see_book == "1")
            {
                ob.interface();
            Re_sear:
                getline(cin, choose2);
                system("color E");
                //Arts_and_Architecture:
                if (!choose2.compare("1"))
                {
                    ob1.print_sections(0, 20);
                }
                //Computer_Science_and_Engineering:
                else if (!choose2.compare("2"))
                {
                    ob2.print_sections(20, 40);
                }
                //Business_and_Economics:
                else if (!choose2.compare("3"))
                {
                    ob3.print_sections(40, 60);
                }
                //Science_and_Mathematics:
                else if (!choose2.compare("4"))
                {
                    ob4.print_sections(60, 80);
                }
                //Education please enter:
                else if (!choose2.compare("5"))
                {
                    ob5.print_sections(80, 100);
                }
                //General_and_News:
                else if (!choose2.compare("6"))
                {
                    ob6.print_sections(100, 120);
                }
                //Error:
                else
                {
                    system("color 04");
                    cout << "Error ==> please enter the right choice:" << endl;
                    goto Re_sear;
                }
            }
            else if (see_book != "2")
            {
                system("color 04");
                cout << "Error ==> please enter the right choice:" << endl;
                goto see;
            }
            //****************************************
            int k = 0;
            ob_s.borrow(0);
            //**************************************
        eq:
            for (int i = 0; i < 120; i++)
            {
                if (!borrowered.compare(ob1.Title[i]))
                {
                    k = 1;
                    ob1.Copies[i] = ob1.Copies[i] - 1;
                    if (ob1.Copies[i] == 0)
                    {
                        ob1._delete(0, 20, 1, i);
                    }

                }
                else if (!borrowered.compare(ob2.Title[i]))
                {
                    k = 2;
                    ob2.Copies[i] = ob2.Copies[i] - 1;
                    if (ob2.Copies[i] == 0)
                    {
                        ob2._delete(0, 20, 1, i);
                    }
                }
                else if (!borrowered.compare(ob3.Title[i]))
                {
                    k = 3;
                    ob3.Copies[i] = ob3.Copies[i] - 1;
                    if (ob3.Copies[i] == 0)
                    {
                        ob3._delete(0, 20, 1, i);
                    }
                }
                else if (!borrowered.compare(ob4.Title[i]))
                {
                    k = 4;
                    ob4.Copies[i] = ob4.Copies[i] - 1;
                    if (ob3.Copies[i] == 0)
                    {
                        ob3._delete(0, 20, 1, i);
                    }
                }
                else if (!borrowered.compare(ob5.Title[i]))
                {
                    k = 5;
                    ob5.Copies[i] = ob5.Copies[i] - 1;
                    if (ob5.Copies[i] == 0)
                    {
                        ob5._delete(0, 20, 1, i);
                    }
                }
                else if (!borrowered.compare(ob6.Title[i]))
                {
                    k = 6;
                    ob6.Copies[i] = ob6.Copies[i] - 1;
                    if (ob6.Copies[i] == 0)
                    {
                        ob6._delete(0, 20, 1, i);
                    }
                }
            }
            if (k == 0)
            {
                system("color 04");
                cout << "Error==>This book not found (try again):" << endl;
                ob_s.borrow(1);
                goto eq;
            }
            cout << "its don" << endl;
        }
        //***********************return_borrowed_item************
        else if (choose_s == "6")
        {
            int j; string ret;
            j = ob_s.return_borrowed_item(0);
            if (borrowered != "")
            {
                cout << "Do you want return this book:" << endl;
                cout << "1-yes:" << endl;
                cout << "2-no:" << endl;
                cout << "please enter 1 or 2" << endl;
            eqi:
                getline(cin, ret);
                system("color E");
                if (ret == "1")
                {
                    for (int i = 0; i < 120; i++)
                    {
                        if (!borrowered.compare(ob1.Title[i]))
                        {
                            ob1.Copies[i] = ob1.Copies[i] + 1;
                        }
                        else if (!borrowered.compare(ob2.Title[i]))
                        {
                            ob2.Copies[i] = ob2.Copies[i] + 1;
                        }
                        else if (!borrowered.compare(ob3.Title[i]))
                        {
                            ob3.Copies[i] = ob3.Copies[i] + 1;
                        }
                        else if (!borrowered.compare(ob4.Title[i]))
                        {
                            ob4.Copies[i] = ob4.Copies[i] + 1;
                        }
                        else if (!borrowered.compare(ob5.Title[i]))
                        {
                            ob5.Copies[i] = ob5.Copies[i] + 1;
                        }
                        else if (!borrowered.compare(ob6.Title[i]))
                        {
                            ob6.Copies[i] = ob6.Copies[i] + 1;
                        }
                    }
                    ob_s._delete(1, j);
                    ob_s.return_borrowed_item(1);
                }
                else if (ret != "2")
                {
                    system("color 04");
                    cout << "Error==>Please enter a true value(1 or 2):" << endl;
                    goto eqi;
                }
                cout << "its don" << endl;
            }
        }
        //************************payment*************************
        else if (choose_s == "7")
        {
            ob_s.payment();
        }
        //***********************print reports*******************
        else if (choose_s == "8")
        {
        ob_s.print_reports();
        }
        //***********************error***************************
        else
        {
            system("color 04");
            cout << "Error==> please enter a true choose:" << endl;
            goto error_s;
        }
        string x, y;
        //***********************Do you want to go to the list of subscribers section?******************
        cout << "Do you want to go to the list of subscribers section?" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
        cout << "please enter 1 or 2" << endl;
    right_choice_s:
        getline(cin, x);
        system("color E");
        //*****************yes***************************************
        if (x == "1")
        {
            //*****************************Do you want to clear the screen?**************************
            cout << "Do you want to clear the screen?" << endl;
            cout << "1-yes" << endl;
            cout << "2-no" << endl;
            cout << "please enter 1 or 2" << endl;
        right_ch_1:
            getline(cin, y);
            system("color E");
            //*****************yes***************************************
            if (y == "1")
            {
                system("cls");
                goto new_operation_s;
            }
            //*****************no****************************************
            else if (y == "2")
            {
                goto new_operation_s;
            }
            //*****************error*************************************
            else
            {
                system("color 04");
                cout << "Error==> please enter the right choice:" << endl;
                goto right_ch_1;
            }
        }
        //*****************error*************************************
        else if (x != "2")
        {
            system("color 04");
            cout << "Error==> please enter a true choose" << endl;
            goto right_choice_s;
        }
    }
    //interface contents:
//*********************************************************************************************
    else if (section1 == "2")
    {
    again:
        cout << "Please enter the operation number you want to perform:" << endl;
        cout << "1-searsh" << endl;
        cout << "2-delete" << endl;
        cout << "3-edite" << endl;
        cout << "4-add" << endl;
    try_again:
        getline(cin, choose);
        system("color E");
        //*****************searsh:*****************************************
        if (choose == "1")
        {
            string choose2 = "0";
            ob.interface();
        Re_search:
            getline(cin, choose2);
            system("color E");
            //Arts_and_Architecture:
            if (!choose2.compare("1"))
            {
                ob1.print_sections(0, 20);
                ob1.search(0, 20);
            }
            //Computer_Science_and_Engineering:
            else if (!choose2.compare("2"))
            {
                ob2.print_sections(20, 40);
                ob2.search(20, 40);
            }
            //Business_and_Economics:
            else if (!choose2.compare("3"))
            {
                ob3.print_sections(40, 60);
                ob3.search(40, 60);
            }
            //Science_and_Mathematics:
            else if (!choose2.compare("4"))
            {
                ob4.print_sections(60, 80);
                ob4.search(60, 80);
            }
            //Education please enter:
            else if (!choose2.compare("5"))
            {
                ob5.print_sections(80, 100);
                ob5.search(80, 100);
            }
            //General_and_News:
            else if (!choose2.compare("6"))
            {
                ob6.print_sections(100, 120);
                ob6.search(100, 120);
            }
            //Error:
            else
            {
                system("color 04");
                cout << "Error ==> please enter the right choice:" << endl;
                goto Re_search;
            }

        }
        //*****************delete:*****************************************
        else if (choose == "2")
        {
            string section;
            ob.interface();
        try_again3:
            getline(cin, section);
            system("color E");
            //Arts_and_Architecture:
            if (section == "1")
            {
                ob1.print_sections(0, 20);
                ob1._delete(0, 20, 0, 0);
            }
            //Computer_Science_and_Engineering:
            else if (section == "2")
            {
                ob2.print_sections(20, 40);
                ob2._delete(20, 40, 0, 0);
            }
            //Business_and_Economics:
            else if (section == "3")
            {
                ob3.print_sections(40, 60);
                ob3._delete(40, 60, 0, 0);
            }
            //Science_and_Mathematics:
            else if (section == "4")
            {
                ob4.print_sections(60, 80);
                ob4._delete(60, 80, 0, 0);
            }
            //Education:
            else if (section == "5")
            {
                ob5.print_sections(80, 100);
                ob5._delete(80, 100, 0, 0);
            }
            //General_and_News:
            else if (section == "6")
            {
                ob6.print_sections(100, 120);
                ob6._delete(100, 120, 0, 0);
            }
            //error:
            else
            {
                system("color 04");
                cout << "Error ==> try again and enter enough 1 or 2 or 3 or 4 or 5 or 6" << endl;
                goto try_again3;
            }
        }
        //*****************edite:******************************************
        else if (choose == "3")
        {
            string section = "0";
            ob.interface();

        try_again2:
            getline(cin, section);
            system("color E");
            //Arts_and_Architecture:
            if (section == "1")
            {
                ob1.print_sections(0, 20);
                ob1.edit(0, 20);
            }
            //Computer_Science_and_Engineering:
            else if (section == "2")
            {
                ob2.print_sections(20, 40);
                ob2.edit(20, 40);
            }
            // Business_and_Economics:
            else if (section == "3")
            {
                ob3.print_sections(40, 60);
                ob3.edit(40, 60);
            }
            //Science_and_Mathematics:
            else if (section == "4")
            {
                ob4.print_sections(60, 80);
                ob4.edit(60, 80);
            }
            //Education:
            else if (section == "5")
            {
                ob5.print_sections(80, 100);
                ob5.edit(80, 100);
            }
            //General_and_News:
            else if (section == "6")
            {
                ob6.print_sections(100, 120);
                ob6.edit(100, 120);
            }
            //error:
            else
            {
                system("color 04");
                cout << "Error ==>try again and enter enough 1 or 2 or 3 or 4 or 5 or 6" << endl;
                goto try_again2;
            }
        }
        //*****************add:********************************************
        else if (choose == "4")
        {
            int ID = 0;
            string section = "0";
            ob.interface();
        try_again4:
            getline(cin, section);
            system("color E");
            //Arts_and_Architecture:
            if (section == "1")
            {
                ob1.add(0, 20, 0);
            }
            //Computer_Science_and_Engineering:
            else if (section == "2")
            {
                ob2.add(20, 40, 0);
            }
            //Business_and_Economics:
            else if (section == "3")
            {
                ob3.add(40, 60, 0);
            }
            // Science_and_Mathematics:
            else if (section == "4")
            {
                ob4.add(60, 80, 0);
            }
            //Education:
            else if (section == "5")
            {
                ob5.add(80, 100, 0);
            }
            //General_and_News:
            else if (section == "6")
            {
                ob6.add(100, 120, 0);
            }
            //error:
            else
            {
                system("color 04");
                cout << "Error ==> try again and enter enough 1 or 2 or 3 or 4 or 5 or 6" << endl;
                goto try_again4;
            }
        ad:
            for (int j = 0; j < indx; j++)
            {
                if (!ob1.Title[indx].compare(ob1.Title[j]))
                {
                    cout << endl;
                    cout << "\tThis book already exists, the number of copies will be increased" << endl << endl;
                    ob1.Copies[j] = ob1.Copies[j] + 1;
                    ob1._delete(0, 0, 1, indx);
                    break;
                }
                else if (!ob2.Title[indx].compare(ob2.Title[j]))
                {
                    cout << endl;
                    cout << "\tThis book already exists, the number of copies will be increased" << endl << endl;
                    ob2.Copies[j] = ob2.Copies[j] + 1;
                    ob2._delete(0, 0, 1, indx);
                    break;
                }
                else if (!ob3.Title[indx].compare(ob3.Title[j]))
                {
                    cout << endl;
                    cout << "\tThis book already exists, the number of copies will be increased" << endl << endl;
                    ob3.Copies[j] = ob3.Copies[j] + 1;
                    ob3._delete(0, 0, 1, indx);
                    break;
                }
                else if (!ob4.Title[indx].compare(ob4.Title[j]))
                {
                    cout << endl;
                    cout << "\tThis book already exists, the number of copies will be increased" << endl << endl;
                    ob4.Copies[j] = ob4.Copies[j] + 1;
                    ob4._delete(0, 0, 1, indx);
                    break;
                }
                else if (!ob5.Title[indx].compare(ob5.Title[j]))
                {
                    cout << endl;
                    cout << "\tThis book already exists, the number of copies will be increased" << endl << endl;
                    ob5.Copies[j] = ob5.Copies[j] + 1;
                    ob5._delete(0, 0, 1, indx);
                    break;
                }
                else if (!ob6.Title[indx].compare(ob6.Title[j]))
                {
                    cout << endl;
                    cout << "\tThis book already exists, the number of copies will be increased" << endl << endl;
                    ob6.Copies[j] = ob6.Copies[j] + 1;
                    ob6._delete(0, 0, 1, indx);
                    break;
                }

            }
            //Arts_and_Architecture:
            if (section == "1")
            {
                ob1.add(0, 20, 1);
            }
            //Computer_Science_and_Engineering:
            else if (section == "2")
            {
                ob2.add(20, 40, 1);
            }
            //Business_and_Economics:
            else if (section == "3")
            {
                ob3.add(40, 60, 1);
            }
            // Science_and_Mathematics:
            else if (section == "4")
            {
                ob3.add(60, 80, 1);
            }
            //Education:
            else if (section == "5")
            {
                ob3.add(80, 100, 1);
            }
            //General_and_News:
            else if (section == "6")
            {
                ob3.add(100, 120, 1);
            }
            if (er_ad == 1)
            {
                goto ad;
            }
        }

        //*****************error*******************************************
        else
        {
            system("color 04");
            cout << "Error==> please enter the right choice:" << endl;
            goto try_again;
        }
        //*****************Do you want to do another operation?***********************
        string x, n;
        cout << "Do you want to do another operation?" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
        cout << "please enter 1 or 2" << endl;
    right_choice:
        getline(cin, x);
        system("color E");
        //*******************yes*******************************************************
        if (x == "1")
        {
            //*******************Do you want to clear the screen?**************************
            cout << "Do you want to clear the screen?" << endl;
            cout << "1-yes" << endl;
            cout << "2-no" << endl;
            cout << "please enter 1 or 2" << endl;
        right_ch:
            getline(cin, n);
            system("color E");
            //*******************yes*******************************************************
            if (n == "1")
            {
                system("cls");
                goto again;
            }
            //*******************no********************************************************
            else if (n == "2")
            {
                goto again;
            }
            //*******************error*****************************************************
            else
            {
                system("color 04");
                cout << "Error==> please enter the right choice:" << endl;
                goto right_ch;
            }
        }
        //*******************no********************************************************
        else if (x == "2")
        {
            goto end;
        }
        //*******************error*****************************************************
        else
        {
            system("color 04");
            cout << "Error==> please enter the right choice:" << endl;
            goto right_choice;
        }
    }
    //*******************error*********************************************************************
    else
    {
        system("color 04");
        cout << "Error==> please enter the right choice:" << endl;
        goto ERR;
    }
end:
    //*****************************************************************************************
    //********************Do you want to go to the main menu?**********************************
    string xx, nn;
    cout << "Do you want to go to the main menu?" << endl;
    cout << "1-yes" << endl;
    cout << "2-no" << endl;
    cout << "please enter 1 or 2" << endl;
right_choice_end:
    getline(cin, xx);
    system("color E");
    //************************yes***************************************************
    if (xx == "1")
    {
        cout << "Do you want to clear the screen?" << endl;
        cout << "1-yes" << endl;
        cout << "2-no" << endl;
        cout << "please enter 1 or 2" << endl;
    right_ch_end:
        getline(cin, nn);
        system("color E");
        //************************yes*************************************************
        if (nn == "1")
        {
            system("cls");
            goto again_end;
        }
        //************************no**************************************************
        else if (nn == "2")
        {
            goto again_end;
        }
        //************************error***********************************************
        else
        {
            system("color 04");
            cout << "Error==> please enter the right choice:" << endl;
            goto right_ch_end;
        }

    }
    //************************no****************************************************
    else if (xx == "2")
    {
        goto end_end;
    }
    //************************error*************************************************
    else
    {
        system("color 04");
        cout << "Error==> please enter the right choice:" << endl;
        goto right_choice_end;
    }
end_end:
    cout << "**********Thanks for using this program*********" << endl;
    return 0;
}



                      

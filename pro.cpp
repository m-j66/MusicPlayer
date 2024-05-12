#include<iostream>
#include<windows.h>
#include<cstdlib>
#include<conio.h>
#include<string>
using namespace std;

									
struct Node
{
  int data_val;
  string name;
  int yearPublished;
  string artist;
  Node *next;
  Node *previous;


};

class Music_player
{
private:

  Node * head, *current, *temp, *prev, *nextptr;

public:
  Music_player ()
  {
    head = NULL;


  }
  //creating the linked list.
  void create (string x, int y, string z)
  {

    if (head == NULL)
      {
	head = new Node;
	head->name = x;
	head->yearPublished = y;
	head->artist = z;
	head->next = NULL;
	head->previous = NULL;
      }
    else
      {
	current = head;
	while (current->next != NULL)
	  {

	    current = current->next;

	  }
	temp = new Node;
	temp->name = x;
	temp->yearPublished = y;
	temp->artist = z;
	temp->next = NULL;
	temp->previous = NULL;
	current->next = temp;



      }



  }
  //printing the linked list.
  void print ()
  {
    cout << endl;
    cout << "                   ----------ALL TRACKS----------\n";
    int c = 1;
    current = head;
    while (current->next != NULL)

      {
	cout << c << " : Song name: " << current->name << "      Arist name: "
	  << current->artist << "\tYear published: " << current->
	  yearPublished << endl;

	c++;
	current = current->next;



      }
    cout << c << " : Song name: " << current->name << "      Arist name: " <<
      current->artist << "\tYear published: " << current->
      yearPublished << endl;




  }
  //searching by song
  void search_SONGNAME (string ssong)
  {
    current = head;
    while (current->name != ssong && current->next != NULL)
      {

	current = current->next;
      }
    if (current->name != ssong)
      cout << "Song not found";
    else
      cout << ssong << " is found in the list...";
  }
//searching the song by artist

  void search_ARTISTNAME (string artsist_name)
  {

    current = head;
    while (current->artist != artsist_name && current->next != NULL)
      {

	current = current->next;
      }
    if (current->artist != artsist_name)
      cout << "Song not found...";
    else
      cout << artsist_name << " is found in the list...";


  }


  //deleting the song by location 
  void del (int d_song)
  {
    cout << "Enter the location of the song to delete:" << endl;
    cin >> d_song;
    current = head;
    temp = head;
    if (head == NULL)
      {
	cout << "Playlist is empty...";
      }
    else if (d_song == 1)
      {
	temp = head;
	head = head->next;


	delete (temp);
	cout << "UpdateD list: " << endl;
	print ();
      }
    else
      {
	while (d_song != 1)
	  {
	    temp = current;
	    current = current->next;
	    d_song--;
	  }
	temp->next = current->next;
	delete (current);
	current = NULL;
	print ();
      }
  }
 //deleting a song  by name
void deleteItem()
{
   string s;
    Node *previous;
   temp = head;

   cout<<"What is the name you wish to delete?\n";
   getline(cin>>ws,s);

   // First, locate the node that contains the item.
   while (temp->name!=s && temp->next != NULL)
{
	  prev = temp;
	 temp = temp->next; 
   }

   // Now take care of deleting it.
   if ( temp != NULL )
   {
      if ( temp == head )
      {
         head = temp->next;
      }
      else
      {
      	Node *c;
    	c=temp->next;
         prev->next = temp->next;
      	 c->previous=prev;   	 
	  }

      delete temp;
      cout<<" Was deleted successfully\n"<< s;
      print();
   }    
}

  
  //adding a new song
  void insert_song (string x, int y, string z)
  {

    temp = new Node;
    temp->name = x;
    temp->artist = z;
    temp->yearPublished = y;
    temp->previous = current;
    temp->next = NULL;
    current->next = temp;
    current = temp;

    print ();
  }

//counting total songs
  void total_songs ()
  {

    current = head;
    int c = 1;
    while (current->next != NULL)
      {
	c++;
	current = current->next;
      }
    cout << c;
  }


  //view by newest to oldest
  void reverse ()
  {

    current = head;
    Node *prev = NULL;
    while (current)
      {
	temp = current->next;
	current->next = prev;
	prev = current;
	head = prev;
	current = temp;
      }
    print ();
  }



};

		

struct node
{
    string name;
    int yearPublished;
    string artist;
    node* next;
};

node *head=NULL;

void push(string x)
{
    node*temp;
    temp=new node;
    temp->name=x ;
    temp->next=head;
    head=temp;
}
bool isempty()
{
    node*temp;
    temp=new node;
    if(head==NULL)
    return true;
    else 
    return false;
}
void pop()
{
    node*temp;
    
    if(isempty())
    {
        cout<<"No history";
    }
    else
    temp=head;
    head=head->next;
    delete(temp);
    
}
void topelement()
{
    
    if(isempty())
    {cout<<"No History";
    }
    else
    {
        cout<<head->name;
    }
}
void print()
{
	node*current;
    if(isempty())
    {
        cout<<"No History ";
    }
    else
    {
	    cout<<"Your History: "<<endl;

        current=new node;
        current=head;
        while(current!=NULL)
        {
            cout<<current->name<<endl;
            current=current->next;
        }
        
    }
}

					
class queue
{
	string playListName;
    public:
	node* front, * rear, * temp, * current;	
    queue()
    {
        front = NULL;
        rear = NULL;
    }
	void setPlayListName(string s)
	{
		playListName=s;
	}
		
	string getPlayListName()
	{
		return playListName;
	}
	
	bool isEmpty()
	{
		if(front==NULL)	
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(string n, int y, string a)
    {
        //creation of the new node
        temp = new node;
        temp->name = n;
        temp->yearPublished = y;
        temp->artist = a;
        temp->next = NULL;

        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }

        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if (isEmpty() == true)
        {
            cout << "Your playlist is empty!";
            return;
        }

        else if (front == rear)
        {
            free(front);
            front = NULL;
            rear = NULL;
        }

        else
        {
            temp = front;
            front = front->next;
            cout<<"\n Name of artist: "<<temp->artist;
			cout<<"\n Name of song: "<<temp->name;
			cout<<"\n Year published: "<<temp->yearPublished;
			cout<<endl;
			cout<<"This is removed from playlist\n";
            free(temp);
        }
    }

	void display()
	{
		temp= front;
		if(isEmpty()==true)
		{
			cout<<"playlist is empty now!";
			return;
	    }
		cout<<getPlayListName();
		cout<<endl;
		while(temp!= NULL)
		{
			cout<<"\n Name of artist: "<<temp->artist;
			cout<<"\n Name of song: "<<temp->name;
			cout<<"\n Year published: "<<temp->yearPublished;
			cout<<endl;
			temp=temp->next;
		}
	}
	
	void deleteFromSpecificPosition(string s)
	{
		temp=front;
		node *ptr;
		ptr=temp->next;
		
		if(front->name==s)
		{
			dequeue();
			cout<<"\nAfter deletion: ";
			display();
			return;
		}
		
		else
		{	
		while((s!=ptr->name) && (ptr->next!=NULL))
		{
			ptr=ptr->next;
			temp=temp->next;
		}
		
		if(ptr->next == NULL && s!= ptr->name)
		{
			cout<<"\n Either the song doesn't exist in the play list or you've entered the wrong spellings!";
			return;
		}
		else
		{	
	
		temp->next= ptr->next;
	 	free(ptr);
	
		if(rear->name==s)
		{
			rear=temp;
		}
		cout<<"\nAfter deletion: ";
		display();
		}
		}	
}
	void playPlaylist()
	{
		string fileName;
		string argument;
		int n;
		
		temp=front;
		
		if(isEmpty()==true)
		{
			cout<<"playlist is empty! ";
			return;
		}
		
		while(temp!=NULL)
		{
		  fileName= temp->name;
		  argument= "open \"" + fileName + ".mp3\" type mpegvideo alias mp3";
		  mciSendString(argument.c_str(), NULL, 0, NULL);

  	 while(1)
   	  {
     	
      cout << "Press 1 to play the file and press 2 to exit the file." << endl;
      cin>>n;
       while((n!=1) && (n!=2))
        {
        	cout<<"You've entered a wrong character! \n";
			cout << "Press 1 to play the file and press 2 to exit the file." << endl;
			cin>>n;
		}
      if(n==1)
      {
      	
	   mciSendString("play mp3", NULL, 0, NULL);
	   push(temp->name);
       cout<<temp->name <<" playing\n";
      
       
      
       
        cout << "Press 0 to pause the file and press 2 to exit the file." << endl;
        cin>>n;
        
	        while((n!=0) && (n!=2))
        {
        	cout<<"You've entered a wrong character! \n";
			cout << "Press 0 to pause the file and press 2 to exit the file." << endl;
			cin>>n;
		}
        	 if(n==0)
      		 {
      		 
       		//pause the audio file
       		mciSendString("pause mp3", NULL, 0, NULL);
    
       			cout<<"Audio file paused after " ;
     		}
     		else if(n==2)
     		{
       		//close the audio file
       		mciSendString("close mp3", NULL, 0, NULL);
       		break;
     		}
}
	  
      
     else if(n==2)
     {
       //close the file and get out of the loop
       mciSendString("close mp3", NULL, 0, NULL);
       break;
     }  
   }
   	temp = temp->next;
   	
}

     cout<<"All songs in the playlist have been played!\n";
 }
};


int main()
{
	Music_player mp;
	queue playList1;
	queue playList2;
	playList1.setPlayListName("My Urdu Songs");
	playList1.enqueue("Gerua",2015, "By: Arijit Singh, Antara Mitra, Pritam Chakraborty");
	playList1.enqueue("Aadat",2004, "Atif Aslam");
	playList1.enqueue("Tum Se Hi",2007, "Mohit Chauhan");
	playList1.enqueue("Tum Hi Ho",2013, "Arijit Singh");
	
	mp.create ("Tum Se Hi", 2007, "Mohit Chauhan");
  mp.create ("Tum hi ho", 2013, "Arijit Singh");
  mp.create ("Middle of the night", 2022, "Elley Duhe");
  mp.create ("Gerua", 2015, " Antara Mitra");
  mp.create ("Blinding Lights", 2019, "The Weeknd");
  mp.create ("Aadat", 2004, "Atif Aslam");

		PlaySound(TEXT("car-ignition.wav"), NULL, SND_FILENAME | SND_ASYNC);// - the correct code for using the playsound function 
        cout << "\t\t\t\t\t\t\tSTARTING UP!!!";
        
        sleep(5);
        
while(1)
{

	int n;
	starting:
		system("CLS");
		cout<<"\n***************Welcome to our Music Player**************\n";
		cout<<"\n*************** Your day is gonna be great!**************\n";
		
		cout<<"\n\t\t1.Tracks";
		cout<<"\n\t\t2.PlayLists";
		cout<<"\n\t\t3.Settings";
		cin>>n;
		while(n>3||n<1)
		{
			cout<<"You've entered a wrong number!";
			cin>>n;
		}
		
		if(n==1)
		{
			goto START2;
		}
		
		else if(n==2)
		{
			goto START;
		}
		else if(n==3)
		{
			goto START3;
		}
		
	START:
		int c;
	system("CLS");
	cout<<"\n\t\t 1. Goto playLists";
	cout<<"\n \t\t2. Create PlayList";
	cout<<"\n \t\t3. Go Back";
	cout<<"\n \t\t4. Exit";
	cin>>c;
		
	while(c < 1 || c > 4)
	{
		cout<<"\n\t\tYou've entered a wrong number.\n Kindly enter from (1-3)";
		cin>>c;
	}
	if(c==1)
	{
		int ch; 
		system("CLS");
		cout<<"\n\t\t1. Playlist 1";
		cout<<"\n\t\t2. Playlist 2";
		cout<<"\n\t\t3. Go Back";
		cout<<"\n\t\t4. Exit";
		cin>>ch;
		while(ch<1 || ch>4)
		{
			cout<<"\nYou've entered a wrong number.\n Kindly enter from (1-4)";
			cin>>ch;
		}
		
		if(ch==1)
	{				
	cout<<playList1.getPlayListName();
	int choice;
	MENU2:
	system("CLS");
	cout<<"\n\t\t 1. View playlist";
	cout<<"\n\t\t 2. Delete from playList";
	cout<<"\n\t\t 3. Add to playList";
	cout<<"\n\t\t4. Play your playList 1";
	cout<<"\n\t\t 5. Go Back";
	cout<<"\n\t\t 6. Exit";
	cin>>choice;
	
	while(choice < 1 || choice > 6 )
	{
		cout<<"\n\t\tNot good with numbers eh?\n Kindly enter from (1-6)";
		cin>>choice;
	}
	switch(choice)
	{
		case 1:	
		    system("CLS");
			playList1.display();
			system("pause");
			goto MENU2;
			
		break;
		
		case 2:
			{
			
			int c;
			system("CLS");
			cout<<"\n\t\t1. Delete from a specific position";
			cout<<"\n\t\t2. Delete first song";
			cout<<"\n\t\t3. Go Back";
			cout<<"\n\t\t4. Exit";
			cin>>c;	
			if(c==1)
			{
				string a;
				playList1.display();
				cout<<"\n\t\t Enter the name of the song you want to delete be careful with spellings and spaces: ";
				getline(cin>>ws,a);
				playList1.deleteFromSpecificPosition(a);
				system("pause");
				goto MENU2;
			}
			else if(c==2)
			{
				system("CLS");
				playList1.dequeue();
				system("pause");
				goto MENU2;
			}
			else if(c==3)
			{
				goto MENU2;
			}
			
			else
			{
				exit(0);
			}
		}
		break;
		
		case 3:
			{
				system("CLS");
			string newSong, newArtist;
			int newYear;
				mp.print();
			cout<<"\n\t\tEnter the name of the song you want to add: ";
			getline(cin>>ws,newSong);
			
			cout<<"\n\t\tEnter the name of the artist: ";
			getline(cin>>ws,newArtist);
			
			cout<<"\n\t\tEnter the year published: ";
			cin>>newYear;
			
			playList1.enqueue(newSong,newYear,newArtist);
			cout<<"\n\t\t Your updated playList is: ";
			playList1.display();
			system("pause");
			goto MENU2;
		}
		break;
		
		case 4:
			system("CLS");
			playList1.playPlaylist();
			system("pause");
			goto MENU2;	
		break;
		
		case 5:
		 goto START;
		break;
		
		case 6:
			exit(0);
		break;	
		
		default:
			cout<<"\t\tWrong entry!";
		
		break;
	}

	}
	
	else if(ch==2)
	{
		if (playList2.isEmpty()==true)
		{
			cout<<"\t\tThis playlist is currently empty!";
			system("pause");
		}
		else
		{
		int x; 
		MENU3:
		system("CLS");
		cout<<playList2.getPlayListName();
		cout<<endl;
		cout<<"\n\t\t 1. View playlist";
		cout<<"\n\t\t 2. Delete from playList";
		cout<<"\n\t\t 3. Add to playList";
		cout<<"\n\t\t 4. Play your playList 2";
		cout<<"\n\t\t 5. Go Back";
		cout<<"\n\t\t 6. Exit";
		cin>>x;
		while(x<1||x > 6)
		{
			cout<<"\n\t\tYou've entered a wrong number!\nKindly enter again:";
			cin>>x;
		}
		
	switch(x)
	{
		case 1:	
		    system("CLS");
			playList2.display();
			system("pause");
			goto MENU3;
			
		break;
		
		case 2:
			{
			
			int c;
			system("CLS");
			cout<<"\n\t\t1. Delete from a specific position";
			cout<<"\n\t\t2. Delete first song";
			cout<<"\n\t\t3. Go Back";
			cout<<"\n\t\t4. Exit";
			cin>>c;	
			if(c==1)
			{
				string b;
				playList2.display();
				cout<<"\n\t\t Enter the name of the song you want to delete be careful with spellings and spaces: ";
				getline(cin>>ws,b);
				playList2.deleteFromSpecificPosition(b);
				system("pause");
				goto MENU3;
			}
			else if(c==2)
			{
				system("CLS");
				playList2.dequeue();
				system("pause");
				goto MENU3;
			}
			else if(c==3)
			{
				goto MENU3;
			}
			
			else
			{
				exit(0);
			}
		}
		break;
		
		case 3:
			{
			system("CLS");
			string Song, Artist;
			int Year;
			mp.print();
			cout<<"\n\t\tEnter the name of the song you want to add: ";
			getline(cin>>ws,Song);
			
			cout<<"\n\t\tEnter the name of the artist: ";
			getline(cin>>ws,Artist);
			
			cout<<"\n\t\tEnter the year published: ";
			cin>>Year;
			
			playList2.enqueue(Song,Year,Artist);
			cout<<"\n\t\t Your updated playList is: ";
			playList2.display();
			system("pause");
			goto MENU3;
		}
		break;
		
		case 4:
			system("CLS");
			playList2.playPlaylist();
			system("pause");
			goto MENU3;	
		break;
		
		case 5:
		 goto START;
		break;
		
		case 6:
			exit(0);
		break;	
		
		default:
			cout<<"Wrong entry!";
		
		break;
	}
	
		
		}
	}
}


	else if(c==2)
	{
		
			string n;
			system("CLS");
			cout<<"\t\tEnter the name of the playList: ";
			getline(cin>>ws,n);
			playList2.setPlayListName(n);
			
		string newSong, newArtist;
		int newYear;
			system("CLS");
			mp.print();
			cout<<"\n\t\tEnter the name of the song you want to add: ";
			getline(cin,newSong);
			cout<<"\n\t\tEnter the name of the artist: ";
			getline(cin,newArtist);
			cout<<"\n\t\tEnter the year published: ";
			cin>>newYear;
			playList2.enqueue(newSong,newYear,newArtist);
			playList2.display();
			system("pause");
	}
	else if(c==3)
	{
		goto starting;
	}
	else
	{
		exit(0);
	}
}

	START3:
		int d;
			system("CLS");
			cout<<"\n\t\t1.History";
			cout<<"\n\t\t2.Themes";
			cout<<"\n\t\t3.Go Back";
			cout<<"\n\t\t4.Exit";
			cin>>d;
			if(d>4||d<1)
			{
				cout<<"You've entered a wrong number!";
				cin>>d;
			}
			
			if(d==1)
			{
				goto stacks;
			}
			else if(d==2)
			{
				int h;
				system("CLS");
				cout<<"\n\t\t1.Theme 1";
				cout<<"\n\t\t2.Theme 2";
				cout<<"\n\t\t3.Theme 3";
				cout<<"\n\t\t4.Theme 4";
				cin>>h;
				if(h==1)
				{
						system("color BD");
						goto START3;
				}
				else if(h==2)
				{
					system("color F6");
					goto START3;
				}
				else if(h==3)
				{
					system("color 0B");
					goto START3;
				}
				else if(h==4)
				{
						system("color 85");
						goto START3;
				}
				else if(h==5)
				{
					goto START3;
				}
				else 
				{
					exit(0);
				}
			}
			else if(d==3)
			{
				goto starting;
			}
			else
			{
				exit(0);
			}
			
			stacks:
				int k;
					system("CLS");
			cout<<"\n\t\t 1.View History";
			cout<<"\n\t\t2.Delete History ";
			cout<<"\n\t\t3.Go Back";
			cout<<"\n\t\t4.Goto Main";
			cout<<"\n\t\t5.Exit";
			cin>>k;
			if(k<1||k>5)
			{
				cout<<"\t\tYou've entered a wrong number!";
				cin>>k;
			}
			
			if(k==1)
			{
				print();
				cout<<endl;
				system("pause");
				goto stacks;
				
				
			}
			else if(k==2)
			{
				pop();
					goto stacks;
				system("pause");
				
			}
			else if(k==3)
			{
				goto START3;
				system("pause");
			}
			else if(k==4)
			{
				goto starting;
			}
			else
			{
				exit(0);
			}
			
			START2:
				
				 int select;
      cout << endl;
      system("CLS");
      					//MAHAM's BLOCK
      cout <<
	"Select any of the options.  \n 1.View all tracks\n 2.Search any song from the list\n 3.Delete any song \n 4.Add any song \n 5.View the total number of songs \n 6.close the app"
	<< endl;
	cout<<"\n7. Go Back";
      cin >> select;

	while(select<1||select>7)
	{
		cout<<"You've enetered a wrong number!";
		cin>>select;
	}
      switch (select)
	{
	case 1:
	  {

	    int selection;
	    system("CLS");
	    cout << "View By: " << endl;

	    cout << "1.Oldest to newest: " << endl;
	    cout << "2.Newsest to oldest: " << endl;
	    cin >> selection;

	    switch (selection)
	      {
	      case 1:
		{
		  mp.print ();
		  system("pause");
		  goto START2;
		  
		  break;
		}
	      case 2:
		{
			
		  
		  mp.reverse ();
		  system("pause");
		  goto START2;
		  break;
		}
	      case 3:
		{
		  exit (0);
		  break;
		}

	      }




	    break;
	  }
	case 2:
	  {
	    int searching_choice;
	    string search_songname;
	    string search_artistname;
	    system("CLS");
	    cout << "Search any song in the list" << endl;
	    cout << "1.search by song\n2.search by artist";
	    cin >> searching_choice;
	    switch (searching_choice)
	      {
	      case 1:
		{
		  cout << "Enter the name of the song" << endl;
		  getline (cin >> ws, search_songname);
		  mp.search_SONGNAME (search_songname);
		  system("pause");
		  goto START2;
		  
		  break;


		}
	      case 2:
		{

		  cout << "Enter the name of the arist" << endl;
		  getline (cin >> ws, search_artistname);
		  mp.search_ARTISTNAME (search_artistname);
		  system("pause");
		  goto START2;
		  
		  break;


		}



	      }

	    break;

	  }

	case 3:
	  {
	    int selection;
	    system("CLS");
	    cout << "Delete By: " << endl;

	    cout << "1.song Number/Location: " << endl;
	    cout << "2.song Name: " << endl;
	    cin >> selection;

	    switch (selection)
	      {
	      case 1:
		{
		  int del_song;
		  
		  mp.del (del_song);
		system("pause");
		  goto START2;
		  
		  break;
		}
	      case 2:
		{
		    mp.deleteItem();
		  system("pause");
		  goto START2;
		    
		  break;
		}
	

	      }
	      break;
	  }
	case 4:
	  {

	    string add_song, add_artist;
	    int add_year;
	    system("CLS");
	    cout << "Enter the name of the song ";
	    getline (cin >> ws, add_song);
	    cout << endl;
	    cout << "Enter the yrae of publishing ";
	    cin >> add_year;
	    cout << "Enter the name of the artist ";
	    getline (cin >> ws, add_artist);
	    mp.insert_song (add_song, add_year, add_artist);
	    system("pause");
		  goto START2;
		  
		break;
	  }
	case 5:
	  {
	  	system("CLS");
	    cout << "Total number of songs are: ";
	    mp.total_songs ();
	    system("pause");
		  goto START2;
		  
		break;
	  }
	case 6:
	  {
	    exit (0);
	  }
	case 7:
		goto starting;
}
	return 0;
}

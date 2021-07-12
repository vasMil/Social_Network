#include <iostream>
#include <string>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

class User{
	
	private:
		string name;
		string mail;
		vector<string> fileToVector(string fileName){  //KALO 8A EINAI NA MPEI SE BIBLIO8IKI KAI NA TO XRHSIMOPOIO APO EKEI!!! (NETWORK, PRIVATE)
			string data;
			vector<string> vec;
			fstream strm;
			strm.open(fileName.c_str(), ios::in | ios::out | ios::app);
			
			while(strm.is_open() && !strm.eof()){
				strm>>data;
				if(data!="\n"){
					vec.push_back(data);
				}
			}
			strm.close();
			return vec;
		}
//		string friendList = name + "_friends.txt";
//		string reqList = name + "_requests.txt";
//		string userWall = name + "_wall.txt";
//		string userStamps = name + "_timestamps.txt";
		
	public:
		User(){
		}
		
		User(string username,string email){
			name=username;
			mail=email;
		}
		
		void setName(string nm){
			name = nm;
		}
		void setMail(string ml){
			mail = ml;
		}
		
		string getName(){
			return name;
		}
		string getMail(){
			return mail;
		}
		string getUser(){
			return name + "\n" + mail + "\n\n";
		}
		vector<string> get_friends(){
			string friendList = name + "_friends.txt";
			int i;
			string data;
			vector<string> filoi;
			filoi = fileToVector(friendList.c_str());
			return filoi;
		}
		
		void show_friends(){
			string friendList = name + "_friends.txt";
			int count=0;
			int i;
			string data;
			vector<string> filoi;
			fstream frnd;
			frnd.open(friendList.c_str(), ios::in | ios::out | ios::app);
			while(frnd.is_open() && !frnd.eof()){
				count++;
				getline(frnd,data);
				filoi.push_back(data);
			}
			frnd.close();
			
			for(i=0;i<count-1;i++){ //to -1 einai gt ka8os grafontai oi filoi patietai kai ena enter
				cout<<i+1<<". "<<filoi[i]<<endl;
			}
		}
		
		vector<string> show_freq(){
			string reqList = name + "_requests.txt";
			int count=0;
			int i;
			string data;
			vector<string> freq;
			fstream requests;
			requests.open(reqList.c_str(), ios::in | ios::out | ios::app);
			while(requests.is_open() && !requests.eof()){
				count++;
				getline(requests,data);
				freq.push_back(data);
			}
			requests.close();
			
			for(i=0;i<count-1;i++){ //to -1 einai gt ka8os grafontai ta freq patietai kai ena enter
				cout<<i+1<<". "<<freq[i]<<endl;
			}
			return freq;
		}
		
		bool isUser(){
			string data;
			fstream users;
			string info[2];
			users.open("users.txt", ios::in | ios::out | ios::app);
			while(!users.eof()){
				users>>data;
				if(data!="\n"){
					info[0]=data;
					users>>info[1];
					if(this->getName()==info[0] && this->getMail()==info[1]){
						users.close();
						return 1;
					}
				}
				else{
					users.ignore(1,'\n');
				}
			}
			users.close();
			return 0;	
		}
		
		void addUser(){
			if(!this->isUser()){
				fstream users;
				users.open("users.txt", ios::in | ios::out | ios::app);
				users<<getUser();
				users.close();
				fstream names;
				names.open("names.txt", ios::in | ios::out | ios::app);
				names<<getName()+"\n";
				names.close();
				cout<<"User register successful!"<<endl;
			}
			else{
				cout<<"Username or Email already exist"<<endl;
			}
		}
		
		void unfriend(){
			string friendList = name + "_friends.txt";
			vector<string> frnds;
			int choice,i;
			cout<<"Select the friend you want to remove: "<<endl;
			frnds = fileToVector(friendList);
			do{
				for(i=0;i<frnds.size()-1;i++){
					cout<<i+1<<". "<<frnds[i]<<endl;
				}
				cin>>choice;
			}while(choice>frnds.size() || choice<1 );
			
			choice -=1;
			frnds.erase(frnds.begin()+choice);
			fstream strm;
			strm.open("temp.txt", ios::in | ios::out | ios::app);
			
			for(i=0;i<frnds.size()-1;i++){
				strm<<frnds[i]<<endl;
			}
			strm.close();
			remove(friendList.c_str());
			rename("temp.txt",friendList.c_str());
		}
			
		
		
};


class Network{
	private:
		
		vector<string> fileToVector(string fileName){
			string data;
			vector<string> vec;
			fstream strm;
			strm.open(fileName.c_str(), ios::in | ios::out | ios::app);
			
			while(strm.is_open() && !strm.eof()){
				strm>>data;
				if(data!="\n"){
					vec.push_back(data);
				}
			}
			strm.close();
			return vec;
		}
		
		vector<string> fileToVector(string fileName,bool i){ //pernaei sto vector kai ta kena!
			string data;
			vector<string> vec;
			fstream strm;
			strm.open(fileName.c_str(), ios::in | ios::out | ios::app);
			
			while(strm.is_open() && !strm.eof()){
				getline(strm,data);
					vec.push_back(data);
			}
			strm.close();
			return vec;
		}
		
		vector<string> common(vector<string> vec1, vector<string> vec2, bool choice, string send){
			string data;
			vector<string> vec;
			int i=0,j=0;

			
			if(choice == 1){
				for(i=0;i<vec1.size()-1;i++){
					for(j=0;j<vec2.size()-1;j++){
						if(vec1[i]==vec2[j]){
							data = vec1[i];
							vec.push_back(data);
						}else{
						}
					}
				}
				return vec;
			}
			
			else if(choice == 0){
				                                         //brisko ta koina stoixeia
				for(i=0;i<vec1.size()-1;i++){
					for(j=0;j<vec2.size()-1;j++){
						if(vec1[i]==vec2[j]){
							data = vec1[i];
							vec.push_back(data);
						}else{
						}
					}
				}				
				
				vec1.pop_back();
				vec2.pop_back();
				vec1.insert( vec1.end(), vec2.begin(), vec2.end() ); //enono ta 2 vectors
				for(j=0;j<vec.size();j++){
					for(i=0;i<vec1.size();i++){
						if(vec1[i]==vec[j] || vec1[i] == send){					//afairo ta koina stoixeia
							vec1.erase(vec1.begin()+i);
						}else{
						}
					}
				}	
				return vec1;
			}
		}
		
		int is_friends(string send, string rec){  //opou send to onoma tou apostolea kai rec to onoma tou paralhpth
			string friendList_send = send + "_friends.txt";
			vector<string> sender_friends;
			sender_friends = fileToVector(friendList_send);
		
			string reqList_send = send + "_requests.txt";
			vector<string> sender_req;
			sender_req = fileToVector(reqList_send);
				
			string friendList_rec = rec + "_friends.txt";
			vector<string> receiver_friends;
			receiver_friends = fileToVector(friendList_rec);
							
			string reqList_rec = rec + "_requests.txt";
			vector<string> receiver_req;
			receiver_req = fileToVector(reqList_rec);
				
			if(common(sender_friends,rec)==1){
				return 1;
			}
			else if(common(sender_req,rec)==1){
				return 2;
			}
			else if(common(receiver_req,send)==1){
				return -1;
			}
			else if(send == rec){
				return -2;
			}
			else{
				return 0;
			}	
		}
			
		int common(vector<string> vec1, string s2){
			string data;
			int i=0;
			for(i=0;i<vec1.size();i++){
				data= vec1[i];
				if(data == s2){
					return 1;
				}
			}
			return 0;
		}
				
		void link_friends(string name1, string name2){
			if(is_friends(name1,name2)!=1 && is_friends(name1,name2)!=-2){
				string friendList1 = name1 + "_friends.txt";
				string friendList2 = name2 + "_friends.txt";
				
				fstream frnd1;
				frnd1.open(friendList1.c_str(), ios::in | ios::out | ios::app);
				frnd1<<name2 + "\n";
				frnd1.close();
				
				fstream frnd2;
				frnd2.open(friendList2.c_str(), ios::in | ios::out | ios::app);
				frnd2<<name1 + "\n";
				frnd2.close();
			}else{
//				cout<<"Not allowed!\n"<<endl;
			}

		}
		
		int search(string fileName, string keyword){
			int i=0;
			string line;
			fstream file;
			file.open(fileName.c_str(), ios::in | ios::out | ios::app);
			while(!file.eof()){
				getline(file,line);
				if(keyword == line){
					return i;
				}else{
					i++;
				}
			}
			file.close();
			return -1; //an den brei th le3h
		}

		
	public:
		
		void acc_freq(User u1){            //opou u1 o xristis p kanei accept
			string friendList = u1.getName() + "_friends.txt";
			string reqList = u1.getName() + "_requests.txt";
			vector<string> vec;
			int choice,i;
			
			//pernao to onoma stous filous tou
			vec = u1.show_freq();
			do{
				cout<<"Type the number of the request you want to accept: "<<endl;
				cin>>choice;
			}while(choice> vec.size()-1 || choice< 1); //to -1 einai gia to enter
			
			choice -= 1;
			link_friends(u1.getName(),vec[choice]);
			string rec = vec[choice];
			link_friends(u1.getName(), rec);
			
			//diagrafo to onoma apo ta friend request
			vec.erase(vec.begin()+choice);
			fstream temp;
			temp.open("temp.txt", ios::in | ios::out | ios::app);
			while(temp.is_open() && i<vec.size()-1){
				temp<<vec[i] + "\n";
				i++;
			}
			temp.close();
			remove(reqList.c_str());
			rename("temp.txt", reqList.c_str());
		}
		
		void rej_freq(User u1){
			string reqList = u1.getName() + "_requests.txt";
			vector<string> vec;
			int choice,i;
			vec= u1.show_freq();
			do{
				cout<<"Type the number of the request you want to reject: "<<endl;
				cin>>choice;
			}while(choice> vec.size()-1 || choice< 1); //to -1 einai gia to enter
			choice -= 1;
			vec.erase(vec.begin()+choice);
			fstream temp;
			temp.open("temp.txt", ios::in | ios::out | ios::app);
			while(temp.is_open() && i<vec.size()-1){
				temp<<vec[i] + "\n";
				i++;
			}
			temp.close();
			remove(reqList.c_str());
			rename("temp.txt", reqList.c_str());
		}
		
		void send_freq(User u1){
			int i,choice,accept,j;
			bool flag=false;
			string friendList = u1.getName() + "_friends.txt";
			
			vector<string> frnds,req,temp,usr;
			frnds = fileToVector(friendList);
			usr = fileToVector("names.txt");
			
			temp = common(frnds,usr,0, u1.getName());
			cout<<"Select the user you want to send a friend request to: "<<endl;
			for(i=0;i<temp.size();i++){
				cout<<i+1<<". "<<temp[i]<<endl;
			}
			cin>>choice; choice -= 1;
			i = is_friends(u1.getName(), temp[choice]);
			do{
				switch(i){
				
					default:
						cout<<"Not an option!"<<endl;
						flag=true;
						break;
					
					case 1:
						cout<<"You are already friends!"<<endl;
						flag=true;
						break;
					
					case 2:
						cout<<"You already have a friend request from the user.\n"<<endl;
						cout<<"If you want to see your pending friend requests press 1: \t";
						cin>>accept;
						if(accept==1){
							acc_freq(u1);
							flag=true;
							break;
						}else{
							flag=true;
							break;
						}
						
					case -1:
						cout<<"Your request is pending"<<endl;
						flag=true;
						break;
						
					case -2:
						cout<<"That is not allowed!\n"<<endl;
						break;
											
					case 0:
						string reqList = temp[choice] + "_requests.txt";
						req = fileToVector(reqList);
						req.push_back(u1.getName());
						req.push_back("\n");
						fstream file;
						file.open("file.txt", ios::in | ios::out | ios::app);
						for(j=0;j<req.size();j++){
							file<<req[j];
						}
						file.close();
						remove(reqList.c_str());
						rename("file.txt", reqList.c_str());
						cout<<"Friend request sent!\n"<<endl;
						flag=true;
						break;
				}
			}while(flag==false);

		}

		void delete_user(){
			int i,choice,j;
			vector<string> vec,vec1;
			string keyword;
			
			//Afairo ton xrhsth apo to arxeio names
			vec = fileToVector("names.txt");
			for(i=0;i<vec.size()-1;i++){
				cout<<i+1<<". "<<vec[i]<<endl;
			}
			cin>>choice; choice -=1;
			keyword = vec[choice];
			vec.erase(vec.begin()+choice);
			
			fstream name;
			name.open("temp.txt", ios::in | ios::out | ios::app);
			
			for(i=0;i<vec.size()-1;i++){
				name<<vec[i]<<"\n";
			}
			name.close();
			remove("names.txt");
			rename("temp.txt","names.txt");
			
			//Afairo ton xrhsth kai apo to arxeio users
			vec1 = fileToVector("users.txt",0);
			j = search("users.txt", keyword);
			vec1.erase(vec1.begin()+j,vec1.begin()+j+3); //sbhno to email tou; kai to keno p exei apo kato tou;
			
			fstream strm;
			strm.open("temp.txt", ios::in | ios::out | ios::app);
			
			for(i=0;i<vec1.size()-1;i++){
				strm<<vec1[i]<<endl;
			}
			strm.close();
			remove("users.txt");
			rename("temp.txt","users.txt");
		}
		
		
};


class Message : public Network{
	private:
		string mnm;	
		
		string get_message(User send, bool reply, string mes){
			set_message(send, mes);
			if(!reply){
				return mes;
			}else{
				return "\t"+mes;
			}
		}		
		
		vector<string> fileToVector(string fileName){
			string data;
			vector<string> vec;
			fstream strm;
			strm.open(fileName.c_str(), ios::in | ios::out | ios::app);
			
			while(strm.is_open() && !strm.eof()){
				getline(strm,data);
				vec.push_back(data);
			}
			strm.close();
			return vec;
		}		
		
		string get_timestamp(){
			const time_t now = time(0);
			const string timestamp = ctime(&now);
			vector<char> cvec = stringToVector(timestamp);
			cvec.pop_back();
			const string td = vectorToString(cvec);
			return td;
		}		
		
		vector<char> stringToVector(string str){
			int i;
			vector<char> cvec(str.begin(), str.end());
			return cvec;
		}		
		
		string vectorToString(vector<char> cvec){
			int i;
			string str;
			for(i=0;i<cvec.size();i++){
				str = str + cvec[i];
			}
			str = str + "\0";
			return str;
		}
				
		bool is_reply(string str){
			vector<char> cvec = stringToVector(str);
			if(cvec[0]== '\t'){
				return 1;
			}else return 0;
		}					
		
		string ret_message(User send){
			string message;
			message = send.getName() + ": " + mnm + "\t\t"  + "Likes: " + "0" +"\t||" + get_timestamp();
			return message;
		}		
		
		
		
	public:
	
		string set_message(User send, string mes){
			string message;
			message = send.getName() + ": " + mes + "\t"  + "Likes: " + "0" +"\t||" + get_timestamp();
			return message;
		}
				
		
};


class Wall : public Message{
	private:
		int choice=-1;

		vector<string> fileToVector(string fileName){
			string data;
			vector<string> vec;
			fstream strm;
			strm.open(fileName.c_str(), ios::in | ios::out | ios::app);
			
			while(strm.is_open() && !strm.eof()){
				getline(strm,data);
				vec.push_back(data);
			}
			strm.close();
			return vec;
		}
		
		vector<char> stringToVector(string str){
			int i;
			vector<char> cvec(str.begin(), str.end());
			return cvec;
		}
		
		string vectorToString(vector<char> cvec){
			int i;
			string str;
			for(i=0;i<cvec.size();i++){
				str = str + cvec[i];
			}
			str = str + "\0";
			return str;
		}
		
		bool can_like(User send, string rec, int messPos){
			int i;
			string userStamps = send.getName() + "_timestamps.txt";
			vector<string> vec;
			vec = fileToVector(userStamps.c_str());
			for(i=0;i<vec.size();i++){
		if(vec[i]==timestamp(rec, messPos)){
					return 0;
				}
			}
			return 1;
		}		
		
		void like(User send, string rec, int messPos){
			
			messPos -=1;
//af3ano kata 1 ta like sto post, teleiono me vector
			string userWall = rec + "_wall.txt";
			vector<string> svec = fileToVector(userWall.c_str());
			
			string nmessage = svec[messPos];
			vector <char> cvec = stringToVector(nmessage);
			string name = send.getName();
			int i = name.size() + 2 + mnm_size(send,rec,messPos) + 1 + 7; //onomaApostolea + :' ' + mege8osMinimatos + \t (to \t metraei gia ena xarakthra) + Likes:' '
			int l = (int)cvec[i]; l +=1;; cvec[i]= (char)l;
			string s1 = vectorToString(cvec);
			svec[messPos] = s1;
			
//pernao to vector se arxeio, diagrafo to prohgoumeno, kano rename	
			fstream temp;
			temp.open("temp.txt", ios::in | ios::out | ios::app);
			for(i=0;i<svec.size()-1;i++){
				temp<<svec[i]<<endl;
			}
			temp.close();
			remove(userWall.c_str());
			rename("temp.txt",userWall.c_str());
		}			
		
		string timestamp(string rec,int messPos){
			int size=0;
			int i;
			char data;
			string userStamps = rec + "_wall.txt";
			vector<string> svec = fileToVector(userStamps.c_str());
			string str = svec[messPos-1];
			vector<char> cvec = stringToVector(str);
			do{
				data=cvec[size];
				size++;
			}while(data!= '|'); size +=1;
			
			cvec.erase(cvec.begin(),cvec.begin()+size);
			
			string str2 = vectorToString(cvec);
			return str2;
		}
		
				int mnm_size(User send, string rec, int messPos){
			string userWall = rec + "_wall.txt";
			int begin,size=0;
			string mes,name;
			char data;
			vector<string> svec = fileToVector(userWall.c_str());
			mes = svec[messPos];
			name = send.getName();
			begin = name.size() + 1;
			do{
				begin++;
				size++;
				data=mes[begin];
			}while(data!='\t');
			return size-1;
		}
		
		bool can_post(User send, string rec){
			string friendList = send.getName() + "_friends.txt";
			string data;
			bool flag=0;
			fstream strm;
			strm.open(friendList.c_str(), ios::in | ios::out | ios::app);
			while(strm.is_open() && !strm.eof()){
				getline(strm,data);
				if(data== send.getName() || data== rec){
					strm.close();
					return 1;
				}
			}
			strm.close();
			return 0;
		}		
		
		vector<string> set_vec(User send){
			vector<string> frnds = send.get_friends();
			frnds.pop_back();
			frnds.push_back("See your wall");
			return frnds;
		}
						
	public:
			
		void post(User send, string rec, int reply, string mes){
			if(can_post(send,rec)){
				string userWall = rec + "_wall.txt";
				fstream wall;
				wall.open(userWall.c_str(), ios::in | ios::out | ios::app);
				if(reply == 0){
					wall<<mes<<endl;
					wall.close();
				}else{
//					reply -= 1;
					vector<string> vec1 = fileToVector(userWall.c_str());
					string temp = mes;
					string repMess = "\t" + temp;
					vec1.insert(vec1.begin() + reply, repMess);
					
					wall.close();
					int i;
					fstream tp;
					tp.open("temp.txt", ios::in | ios::out | ios::app);
					for(i=0;i<vec1.size()-1;i++){
						tp<<vec1[i]<<endl;
					}
					tp.close();
					remove(userWall.c_str());
					rename("temp.txt", userWall.c_str());
				}
			}else{
				cout<<"You can not post to that wall!"<<endl;
			}
		}
		
		void like_post(User send, string rec, int messPos){
			if(can_like(send,rec,messPos)){
				//pernao to tag tou mnmtos sto arxeio tou xrhsth
				string userStamps = send.getName() + "_timestamps.txt";
				string userWall = rec + "_wall.txt";
				fstream td;
				td.open(userStamps.c_str(), ios::in | ios::out | ios::app);
				td<<timestamp(rec, messPos)<<endl;
				td.close(); 
				like(send,rec,messPos);
				cout<<"You just liked the post"<<endl;
		
			}else{
				cout<<"You have already liked the post!"<<endl;
			}
		}
		
		vector<string> get_wall(string rec){
			string userWall = rec + "_wall.txt";
			vector<string> wall = fileToVector(userWall.c_str());
			return wall;
		}
				
		void show_wall(string rec){
			int i;
			vector<string> wall = get_wall(rec);
			cout<<"\n\n\t\t\t\t\t\t"<<rec<<"'s Wall:\n\n\n"<<endl;
			for(i=0;i<wall.size()-1;i++){
				cout<<"\t\t\t"<<i+1<<". "<<wall[i]<<endl;
			}
			cout<<"\n\n\n"<<endl;
		}
		
friend class Menu;
		
};


class Menu: public Wall{
	private:
		string name;
		string mail;
		int choice = 0;
		int ch_2 = 0;
		int ar=0,num;
		bool log=0;
		string mes;
		vector<string> wall;
		
		User login(){
			cout<<"Username: ";
			cin>>name;
			cout<<"Email: ";
			cin>>mail;
			User cur (name,mail);
			if(cur.isUser()){
				cout<<"Login successful\n"<<endl;
				log=1;
				return cur;			
			}
			else{
				cout<<"Username or Email do not match"<<endl;
				log=0;
			}
		}
		
		User registration(){
			cout<<"Username: ";
			cin>>name;
			cout<<"Email: ";
			cin>>mail;
			User cur (name,mail);
			if(cur.isUser()){
				cout<<"User already exists\n"<<endl;
				log=0;
				return cur;	
			}
			else{
				cur.addUser();
			}
		}		
		
		int second(){
			int sec_choice;
			cout<<"\n\n"<<endl;
			cout<<"Pick an option:"<<endl;
			cout<<"1. Post a message"<<endl;
			cout<<"2. Reply to a message"<<endl;
			cout<<"3. Like a message"<<endl;
			cout<<"4. Just to spy"<<endl;
			cout<<"5. Go Back"<<endl;
			cin>>sec_choice;
			return sec_choice;
		}		
			
		string first(User send){
			int i,f_choice;
			cout<<"\n\n"<<endl;
			vector<string> vec = set_vec(send);
			for(i=0;i<vec.size();i++){
				cout<<i+1<<". "<<vec[i]<<endl;
			}
			do{
				cout<<"Give the number that corresponds with the wall you want to access: "<<endl;
				cin>>f_choice;
			}while(f_choice>vec.size() || f_choice<0);
			f_choice -= 1;
			
			if(vec[f_choice] == "See your wall"){
				return send.getName();
			}else{
				return vec[f_choice];
			}
		}			
								
	public:
		
		bool getlog(){
			return log;
		}
		
		User start(){
			int x;
			cout<<"1. Login"<<endl;
			cout<<"2.Register"<<endl;
			
			do{
				cin>>x;
				if(x==1){
					return this->login();
				}
				else if(x==2){
					return this->registration();
				}
				else{
					cout<<"That is not a valid number\nTry again: ";
					x= -1;
				}
			}while(x==-1);
		}					
		
		int mainMenu(User cur){
			while(log==1){
				cout<<"\n\n"<<endl;
				cout<<"Menu:"<<endl;
				cout<<" ______________________________________"<<endl;
				cout<<"|                                      |"<<endl;
				cout<<"| 1. See your wall or a friend's wall  |"<<endl;
				cout<<"| 2. Send a friend request             |"<<endl;
				cout<<"| 3. Accept or Reject a friend request |"<<endl;
				cout<<"| 4. See my friends                    |"<<endl;
				cout<<"| 5. Back                              |"<<endl;
				cout<<"| 6. Log out                           |"<<endl;
				cout<<"| 7. Exit                              |"<<endl;
				cout<<"|______________________________________|"<<endl;
				cin>>choice;
				
				switch (choice){
					case 1:
						name = first(cur);
						ch_2 = second();
						wall = get_wall(name);
						
						switch(ch_2){
							case 1:
								cout<<"Type your message here:\t";
								cin.clear();
								cin.ignore();
								getline(cin,mes);
								mes = set_message(cur,mes);
								post(cur,name,0,mes);
								break;
							case 2:
								do{
									cout<<"Select the post you want to reply to"<<endl;
									cin.clear();
									cin.ignore();
									cin>>num;
								}while(num>wall.size() || num<0);
								cout<<"Type your message here:\t";
								cin.ignore();
								getline(cin,mes);								
								mes = set_message(cur,mes);						
								post(cur,name,num,mes);
								break;
							case 3:
								do{
									cout<<"Select the post you want to like"<<endl;
									cin>>num;
								}while(num>wall.size() || num<0);							
								like_post(cur,name,num);
								break;
							case 4:
								show_wall(name);
								break;
							case 5:
								cout<<"\n\nYou are going back..."<<endl;
								break;
							default:
								cout<<"That is not an option"<<endl;
								break;				
						}
						break;
					case 2:
						send_freq(cur);
						break;
					case 3:
						cout<<"\nAccept--> 1\nReject--> 0\nYour Input:\t"<<endl;
						cin>>ar;
						if(ar==1){
							acc_freq(cur);
						}else if(ar==0){
							rej_freq(cur);
						}else{
							cout<<"Not an option!\n\n"<<endl;
						}
						break;
					case 4:
						cout<<"\nYou are friends with:"<<endl;
						cur.show_friends();
						cout<<"\n\n\n"<<endl;
						break;
					case 5:
						cout<<"\nGoing back...(logging out)\n"<<endl;
						log=0;
						break;
					case 6:
						cout<<"You have been successfully loged out\n"<<endl;
						log=0;
						break;
					case 7:
						exit(0);
						break;
					default:
						cout<<"That is not an option, try again!\n"<<endl;								
				}
			}
		}
};


int main(){
	Menu test;
	User cur;
//	Network n1;
//	int l;
//	User u1("Vasilis","vasilis@gmail.com");
//	Message m1,m2;
//	User u2("Aris","aris@gmail.com");
//	u1.addUser();
//	u2.addUser();
	
//	cur = test.login();
//	while(test.mainMenu(cur)!=-1 && test.getlog()==0){
//		test.login();
//	}


//______________________________________________________________
//	cur= test.start();
//	while(test.mainMenu(cur)!=-1 && test.getlog()==0){
//		test.start();
//
//	}
//______________________________________________________________


//	cout<<"OI FILOI PRIN"<<endl;
//	u1.show_friends();
//	cout<<"\nTA FREQ PRIN"<<endl;
//	n1.rej_freq(u1);
//	cout<<"\nOI FILOI META"<<endl;
//	u1.show_friends();
//	cout<<"\nTA FREQ META"<<endl;
//	u1.show_freq();

//	n1.delete_user();
	
//	u1.unfriend();

//	m1.post(u1,u2,0);
//	m1.post(u1,u2,0);
//	m1.post(u1,u2,2);
	


//	l = m1.get_likes();	
//	cout<<l<<endl;
//	m1.like_post(u1,u2,3);
//	l = m1.get_likes();
//	cout<<l<<endl;
//	m1.like_post(u2,u2,0);
//	l = m1.get_likes();
//	cout<<l<<endl;


	do{
		cur = test.start();
	}while(test.mainMenu(cur)!=-1 && test.getlog()==0);
	
	test.mainMenu(cur);

}

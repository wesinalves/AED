#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class User{
    public:
        User(){}
        User(string name, string email){
            this->name = name;
            this->email = email;
        }
        string getName(){return name;}
        string getEmail(){return email;}
        void getAllPosts(ifstream& file){
            string line;
            while(getline(file,line)){
                stringstream ss(line);
                string id,text,likes,name;
                getline(ss, id, ',');
                getline(ss, text, ',');
                getline(ss, likes, ',');
                getline(ss, name, ',');
                if (name == this->name)
                    cout << line << endl;
                
            }
            cout << "\n";
        }
    private:
        string name;
        string email;

};

class Post{
    public:
        Post(int id, string text, User user){   
            this->id = id;
            this->text = text;
            this->user = user;
            likes = 0;
        }
        void save(ofstream& file){
            if(!file){
                cerr << "Erro ao abrir o arquivo\n";
            }
            file << id << "," << text << "," << likes << "," << user.getName() <<endl;
        }
    private:
        int id;
        string text;
        int likes;
        User user;
};

int main(){
    User u1 = User("wesin", "wesinec@gmail.com");
    User u2 = User("joao", "joao@gmail.com");
    Post p1 = Post(1,"meu primeiro post", u1);
    Post p2 = Post(2,"meu segundo post", u1);
    Post p3 = Post(3, "meu primeiro post", u2);

    // ofstream fout("posts.txt", ios::app);
    // p1.save(fout);
    // p2.save(fout);
    // p3.save(fout);
    
    ifstream fin("posts.txt");
    u1.getAllPosts(fin);

    return 0;
}
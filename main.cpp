//Library Management System

#include<iostream>
#include<vector>
#include<map>
#include<string>

class Book{
private:
    int id;
    std::string title;
    std::string author;
    bool isAvailable;

public:
    Book(int i , std::string t, std::string a) //Constructor
        : id(i) , title(t) , author(a),
isAvailable (true) {}

    void borrowBook() {isAvailable = false;}
    void returnBook() {isAvailable = true;}

    bool available() const {return isAvailable;}

    int getId() const { return id; }
    const std::string& getTitle() const { return title; }
    const std::string& getAuthor() const { return author; }

    void display() const {                     //Function
        std::cout << "Book ID: " << id << std::endl;
        std::cout << "Title :" << title << std::endl;
        std::cout << "Author : " << author << std::endl;
        std::cout << "Available: " 
    << (isAvailable ? "Yes" : "No")
                    << std::endl;

    }

};

class Member {
protected:
    int memberId;
    std::string name;
public:
    Member(int id, std::string n) : memberId(id), name(n) {}

    int getId() const { return memberId; }
    const std::string& getName() const { return name; }

    virtual std::string getType() const { return "Member"; }
    virtual std::string getExtra() const { return std::string(); }

    virtual void displayInfo() const {   //Vitural Function
        std::cout << "Member ID: " << memberId << std::endl;
        std::cout << "Name: " << name << std::endl;
    }
};

class Student : public Member { //Derived Class (Inheritance)
    private:
    std::string course;
    public:
    Student(int id, std::string n, std::string c)
        : Member(id, n), course(c){}
    const std::string& getCourse() const { return course; }
    std::string getType() const override { return "Student"; }
    std::string getExtra() const override { return course; }
    void displayInfo() const override {
        Member::displayInfo();
        std::cout << "Course: " << course << std::endl;
    }
};

class Library {
private:
    std::vector<Book> books;   //(Standard Template Library)
    std::map<int, Member*> members;
public:
    Library() = default;
    ~Library() {              //Destructor
        for (auto &p : members) delete p.second;
        members.clear();
    }
    void addBook(const Book& book){
        books.push_back(book);
    }
    void addMember(Member* member){
        members[member->getId()] = member;
    }
    void showBooks() const {
        for (const auto& book : books){
            book.display();
            std::cout << "------------------" << std::endl;
        }
    }
    void showMembers() const {
        for (const auto& pair : members){
            pair.second->displayInfo();
            std::cout << "------------------" << std::endl;
        }
    }

};


int main(){
    Library lib;
    lib.addBook(Book(1, "Theory of Everything", "Stephen Hawking"));
    lib.addBook(Book(2, "Theory of Relativity", "Albert Einstein"));
    lib.addBook(Book(3, "The Selfish Gene", "Richard Dawkins"));
    lib.addBook(Book(4,"Everthing but You","Alex Root" ));
    lib.addBook(Book(5,"You and Me", "Richard "));
    lib.addBook(Book(6, "Hope " , "James Walcott"));

    lib.addMember(new Student(101, "Rohan" , "Mathematics"));
    lib.addMember(new Student(102,"Siya", "Physics"));
    lib.addMember(new Student(103,"Raj" , "Chemistry" ));
    lib.addMember(new Student(104, "Aditya" , "Physics"));
    lib.addMember(new Student(105, "Aryan" , "Mathematics"));
    std::cout << "Library Books:" << std::endl;
    lib.showBooks();

    std::cout << "Library Members:" << std::endl;
    lib.showMembers();

    return 0;

}
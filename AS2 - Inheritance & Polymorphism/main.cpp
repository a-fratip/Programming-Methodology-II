#include "Reference.h"
#include "Article.h"
#include "Book.h"
#include "TextBook.h"
#include "ReferenceManager.h"

#include <iostream>

using namespace std;

int main() {
    
    cout << "\n---------------Test 1: Reference class---------------" << endl << endl;
    cout << "Creating a default reference..." << endl;
    Reference *r1 = new Reference(); // test default constructor
    // test getters
    cout << r1->get_id() << endl;
    cout << r1->get_title() << endl;
    cout << r1->get_author() << endl;
    cout << r1->get_pub_year() << endl;
    // test setters
    cout << "Updating default reference..." << endl;
    r1->set_id(1);
    r1->set_title("Book title");
    r1->set_author("Someone");
    r1->set_pub_year(2000);
    
    r1->print(); // test print function 
    
    cout << "Creating a new reference..." << endl;
    Reference *r2 = new Reference(2,"My favorite book","Me",2002);
    r2-> print();
    
    delete r1;
    delete r2;
    
    cout << "\n---------------Test 2: Article class---------------" << endl << endl;
    cout << "Creating a default article..." << endl;
    Article *a1 = new Article(); // test default constructor 
    a1->print();
    // test setters and getter
    cout << "Updating default article..." << endl; 
    a1->set_pub_location("Montreal");
    a1->set_start_page(5);
    a1->set_end_page(50);
    cout << a1->getNumberOfPages() << endl;
    
    a1->print(); // test print function 
    
    cout << "Creating a new article..." << endl;
    Article *a2 = new Article(3, "Another book title", "Another author", 2020, "Iowa", 10, 30);
    a2->print();
    
    delete a1;
    delete a2;
    
    cout << "\n---------------Test 3: Book class---------------" << endl << endl;
    cout << "Creating a default book..." << endl;
    Book *b1 = new Book(); // test default constructor
    b1->print();
    // test setters and getters
    cout << "Updating default book..." << endl;
    b1->set_pub("Publisher x");
    b1->set_num_pages(100);
    cout << b1->getNumberOfPages() << endl;
    cout << b1->get_pub() << endl;
    
    cout << "Creating a new book..." << endl;
    Book *b2 = new Book(4, "Another x book title", "Another x author", 2023, "Marty", 150);
    b2->print(); // test print function
    
    delete b1;
    delete b2;
    
    cout << "\n---------------Test 4: TextBook class---------------" << endl << endl;
    cout << "Creating a default book..." << endl;
    TextBook *tb1 = new TextBook(); // test default constructor 
    tb1->print();
    // test setter and getter
    tb1->set_url("www.myURL.com");
    cout << tb1->get_url() << endl;
    
    cout << "Creating a new TextBook..." << endl;
    TextBook *tb2 = new TextBook(5, "Another xy book title", "Another xy author", 2024, "Martin", 175, "www.someURL.com");
    tb2->print(); // test print function
    
    delete tb1;
    delete tb2;
    
    cout << "\n---------------Test 5: ReferenceManager class---------------" << endl << endl;
    cout << "Creating 3 base class pointers..." << endl;
    Reference *p1 = new Article(1, "An article title", "Some article author", 2020, "Montreal", 11, 27);
    Reference *p2 = new Book(2, "A book title", "Some book author", 2021, "Some book publisher", 100);
    Reference *p3 = new TextBook(3, "A textbook title", "Some textbook author", 2022, "Some textbook publisher", 150, "www.someURL.com");
    
    cout << "Creating an array to hold 3 references..." << endl;
    ReferenceManager *rm = new ReferenceManager(3);
    // test add function 
    cout << "Adding references..." << endl;
    if (rm->add(*p1))
        cout << "First reference was added..." << endl;
    else
        cout << "First reference could not be added..." << endl;
        
    if (rm->add(*p2))
        cout << "Second reference was added..." << endl;
    else 
        cout << "Second reference could not be added..." << endl;
        
    if (rm->add(*p3))
        cout << "Third reference was added..." << endl;
    else 
        cout << "Third reference could not be added..." << endl;
    // test print function    
    cout << "List of references added to the array..." << endl;
    rm->print_references();
    // test get function
    cout << "Getting the id of the element at position 1..." << endl;
    cout << rm->get(1) << endl;
    // test search function
    cout << "Searching array for a reference with id #3..." << endl;
    if (rm->search(3))
        cout << "Reference with id #3 was found..." << endl;
    else 
        cout << "Refernce with id #3 was not found..." << endl;
    cout << "Searching array for a refernce with id #5..." << endl;    
    if (rm->search(5))
        cout << "Reference with id #5 was found..." << endl;
    else 
        cout << "Reference with id #5 was not found..." << endl;
    
    cout << "Trying to add a fourth reference to the array..." << endl;
    Reference *p4 = new Book();
    if (rm->add(*p4))
        cout << "Fourth reference was added.." << endl;
    else 
        cout << "Could not add reference, max references reached!" << endl;
    // test delete function
    cout << "Trying to remove element at position 6..." << endl;
    if (rm->Delete(6))
        cout << "Element at position 6 was removed..." << endl;
    else
        cout << "6 is an invalid position!" << endl;
    cout << "Removing element at position 2..." << endl;    
    if (rm->Delete(1))
        cout << "Element at position 2 was removed..." << endl;
    else 
        cout << "Could not remove element at position 2!" << endl;
        
    cout << "List of references after removal..." << endl;
    rm->print_references();
    
    cout << endl;
    
    delete rm;
   
    return 0;
    
} 
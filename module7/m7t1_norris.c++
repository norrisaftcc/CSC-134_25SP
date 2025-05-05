#include <iostream>
using namespace std;

// CSC 134
// M7T1 - Restaurant Rating
// norrisa
// 4/28/25
// Use Restaurant class to store user ratings

// Next time we'll put the class in a separate file
class Restaurant {
  private:
    string name;    // the name
    double rating;  // 0 to 5 stars

  public:
	// constructor 
	Restaurant(string n, double r) {
		name = n;
		rating = r;
	}
    // empty constructor
    Restaurant() {
        // does nothing
    }
	// getters and setters
    void setName(string n) {
        name = n; 
    }
    void setRating(double r) {
        rating = r;
    }
    string getName() const {
        return name;
    }
    double getRating() const {
        return rating;
    }
    // Display the information
    void showInfo() {
        cout << "Restaurant Name: " << name << endl;
        cout << "Rating: " << rating << endl;
        // could also use self->name
    }
};

int main() {
    cout << "M7T1 - Restaurant Reviews" << endl;
    // First create a restaurant
    Restaurant rest1 = Restaurant("Mi Casita", 4);

    // Next ask the user to enter one
    Restaurant rest2 = Restaurant(); 
    // get the name and rating
    cout << "Restaurant Name: ";
    string name;
    double rating;
    // This is how you can get a name containing spaces
    getline(cin, name); 
    cout << "Restaurant Rating: ";
    cin >> rating;
    rest2.setName(name);
    rest2.setRating(rating);

    // Finally, show all the data.
    cout << "----------" << endl;
    rest1.showInfo();
    rest2.showInfo();


    return 0;

}
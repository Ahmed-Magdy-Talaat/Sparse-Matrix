#include <iostream>

using namespace std;


// Define a struct for a listnode which contains an integer data, an index, and pointers to the next and previous nodes
struct listnode {
    int data;
    int indx;
    listnode *next;
    listnode *prev;
};




// Define a class for a List
class List {

public:

    // Initialize an integer length and pointers to the head and tail of the list, as well as an array length
    int length{};
    listnode *head = nullptr;
    listnode *tail{};
    int arrlength = 0;


    // Define a default constructor which creates a head node with data 0 and index -1, and no next pointer
    List() {
        head = tail = new listnode();
        head->data = 0;
        head->indx = -1;
        head->next = nullptr;
    }



    // Define a constructor which takes an integer x as input and creates a head node with data 0, index -1, no next pointer, and sets arrlength to x
    List(int x) {
        arrlength = x;
        head = tail = new listnode();
        head->data = 0;
        head->indx = -1;
        head->next = nullptr;
    }



    // Define a function that links two nodes together by setting their next and prev pointers
    void link(listnode *first, listnode *second) {
        if (first) {
            first->next = second;
        }
        if (second) {
            second->prev = first;
        }
    }



    // Define a function that embeds a new node with a given id and value after a given previous node
    listnode *embed_after(listnode *prev, int id, int val) {
        listnode *middle = new listnode();
        middle->data = val;
        middle->indx = id;
        listnode *after = prev->next;
        link(prev, middle);

        // If the next node after the middle node is null, set tail to the middle node
        if (!after) {
            tail = middle;
        } else {
            link(middle, after);
        }
        return middle;
    }



    // Define a function that makes a list node with a given id and a boolean flag
    listnode *make_list(int id, bool f) {
        listnode *prev = head;

        // Iterate through the list until the next node's index is greater than or equal to the given id
        while (prev->next && prev->next->indx < id) {
            prev = prev->next;
        }

        bool found = prev->next && prev->next->indx == id;

        if (found)
            return prev->next;
        if (!f)
            return nullptr;
        return embed_after(prev, id, 0);
    }



    // Define a function that sets the value of a node with a given id
    void set_value(int id, int val) {
        make_list(id, true)->data = val;
    }



    // Define a function that prints the values of all nodes in the list
    void print() {
        listnode*temp = head->next;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }



    // Define a function that gets the value of a node with a given id
    int get_value(int id) {
        listnode *l = make_list(id, false);
        return l->data;
    }

};





struct Row_linkedlist{


    // A struct for a row in the sparse matrix, contains a linked list object and pointers to the next and previous rows, as well as integers for the number of columns and rows

    List l;

    Row_linkedlist *next;

    Row_linkedlist *prev;

    int c;

    int r;
};

class matrix {

    // Define a class for a sparse matrix
    Row_linkedlist *HEAD{};
    Row_linkedlist *TAIL{};
    int cols = 0;
    int rows = 0;

public:


    // constructor which takes two integers as input and assigns them to the number of rows and columns in the matrix and creates a dummy node with index -2
    matrix(int r, int c) {
        cols = c;
        rows = r;
        HEAD = TAIL = new Row_linkedlist();
        HEAD->r = -2;
    }



    // function to link two rows together by setting their next and prev pointers
    void link(Row_linkedlist *first, Row_linkedlist *second) {
        if (first) {
            first->next = second;
        }
        if (second) {
            second->prev = first;
        }
    }





    // function to insert a new row after a given row
    Row_linkedlist *embed_after_list(Row_linkedlist *prev, int row) {
        Row_linkedlist *middle = new Row_linkedlist();
        middle->c = cols;
        middle->r = row;
        Row_linkedlist *after = prev->next;
        link(prev, middle);

        // if the next row after the middle row is null, set TAIL to the middle row
        if (!after) {
            TAIL = middle;
        } else {
            link(middle, after);
        }
        return middle;
    }




    // function to get a row with a given index and a boolean flag
    Row_linkedlist *get_list(int row, bool flag) {
        Row_linkedlist *prev = HEAD;

              // Iterate through the rows until the next row's index is greater than or equal to the given index
        while (prev->next && prev->next->r < row) {
            prev = prev->next;
        }
        bool found_list = prev->next && prev->next->r == row;
        if (found_list)
            return prev->next;

        // if flag is false, return nullptr
        if (!flag)
            return nullptr;
        return embed_after_list(prev, row);
    }



    // function to set the value of a cell in the matrix
    void set_value_Matrix(int rows, int cols, int val) {
        // get the row of the cell
        Row_linkedlist *L = get_list(rows, true);
        // set the value of the cell using the linked list function
        L->l.set_value(cols, val);
    }



    // function to get the value of a cell in the matrix
    int get_value_Matrix(int rows, int cols) {
        // get the row of the cell
        Row_linkedlist *L = get_list(rows, false);
        // return the value of the cell using the linked list function
        if (L) {
            return L->l.get_value(cols);
        }
    }



    // function to print the non-zero elements of the matrix
    void print_matrix_nonzero() {
        cout << "\nPrint Matrix: " << rows << " x " << cols << "\n";
        for (Row_linkedlist *cur = HEAD->next; cur; cur = cur->next) {
            cur->l.print();
            cout << endl;
        }
    }



    // Function to add two matrices
    void add_matrix(matrix b) {
        // Check if the matrices have the same dimensions
        if (this->cols != b.cols || this->rows != b.rows) {
            cout << "This Adding operation can't be done : Matrices dimensions don't match"<<endl;
        } else {
            // Iterate through the rows and columns of the matrices and add the corresponding cell values
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++) {
                    this->set_value_Matrix(i, j, this->get_value_Matrix(i, j) + b.get_value_Matrix(i, j));
                }
            }
        }
    }



    // Function to subtract two matrices
    void subtract_matrix(matrix b) {
        // Check if the matrices have the same dimensions
        if (this->cols != b.cols || this->rows != b.rows) {
            cout << "This Subtraction operation can't be done : Matrices dimensions don't match"<<endl;
        } else {
            // Iterate through the rows and columns of the matrices and subtract the corresponding cell values
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++)
                    this->set_value_Matrix(i, j, this->get_value_Matrix(i, j) - b.get_value_Matrix(i,j));
		}
	}
   }




    // function to multiply two matrices
    void Multiply_matrix(matrix b, matrix c) {
	if (this->cols != b.rows) {
            cout << "This Multiplication operation can't be done : Matrices dimensions couldn't match";
        }
	else {

	    // iterate through the rows and columns of the first matrix
            for (int i = 0; i < this->rows; ++i) {

                for (int j = 0; j < b.cols; ++j) {

                    int result = 0;

                    // iterate through the columns of the first matrix and the rows of the second matrix

                    for (int k = 0; k < this->cols; ++k) {

                        result += this->get_value_Matrix(i, k) * b.get_value_Matrix(k, j);
                    }
                    c.set_value_Matrix(i, j, result);
                }
            }
        }
    }
};

void test(){

    matrix m1(2,3),m2(3,2);
    matrix m3(2,2);
    m3.set_value_Matrix(0,0,0);
    m3.set_value_Matrix(0,1,0);
    m3.set_value_Matrix(1,0,0);
    m3.set_value_Matrix(1,1,0);

    m1.set_value_Matrix(0,0,1);
    m1.set_value_Matrix(0,1,2);
    m1.set_value_Matrix(0,2,3);
    m1.set_value_Matrix(1,0,4);
    m1.set_value_Matrix(1,1,5);
    m1.set_value_Matrix(1,2,6);

    m2.set_value_Matrix(0,0,7);
    m2.set_value_Matrix(0,1,8);
    m2.set_value_Matrix(1,0,9);
    m2.set_value_Matrix(1,1,10);
    m2.set_value_Matrix(2,0,11);
    m2.set_value_Matrix(2,1,12);

    m1.print_matrix_nonzero();
    m2.print_matrix_nonzero();

    m1.Multiply_matrix(m2,m3);
    m3.print_matrix_nonzero();
    m2.add_matrix(m1);
    m2.subtract_matrix(m1);
}

int main(){

test();
}

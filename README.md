<!DOCTYPE html>
<html>
  <head>
    <title>Sparse Matrix using Linked List</title>
    <style>
      /* Add CSS styles here */
    </style>
  </head>
  <body>
    <h1>Sparse Matrix using Linked List</h1>
    <p>This project implements a sparse matrix using a linked list in C++. The sparse matrix is a matrix with few non-zero elements, and this implementation reduces the memory usage compared to dense matrix representation.</p>
    <h2>Getting Started</h2>
    <p>These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.</p>
    <h3>Prerequisites</h3>
    <p>You need to have a C++ compiler installed on your machine in order to run the code.</p>
    <h3>Installing</h3>
    <ul>
      <li>Clone the repository to your local machine</li>
      <li>Navigate to the project directory</li>
      <li>Compile the code using your preferred C++ compiler</li>
      <li>Run the executable file</li>
    </ul>
    <h2>Usage</h2>
    <p>The project contains two classes:</p>
    <ul>
      <li>List class which is a linked list class that stores the non-zero elements in the matrix.</li>
      <li>matrix class which is a sparse matrix class that uses the linked list class to store the non-zero elements of the matrix.</li>
    </ul>
    <p>The matrix class has several member functions, including:</p>
    <ul>
      <li>A constructor which takes two integers as input and assigns them to the number of rows and columns in the matrix.</li>
      <li>A function to link two rows together by setting their next and prev pointers.</li>
      <li>A function to insert a new row after a given row.</li>
      <li>A function to get a row with a given index and a boolean flag.</li>
      <li>A function to set the value of a cell in the matrix.</li>
      <li>A function to get the value of a cell in the matrix.</li>
      <li>A function to print the non-zero elements of the matrix.</li>
      <li>A function to add two matrices.</li>
      <li>A function to subtract two matrices.</li>
      <li>A function to multiply two matrices.</li>
    </ul>
    <p>You can use the matrix class in your code by creating an object and calling its member functions as needed.</p>
    <h2>Conclusion</h2>
    <p>Conclusion
This project demonstrates the implementation of a sparse matrix using a linked list in C++. By using a linked list to store the non-zero elements of the matrix, the memory usage is reduced compared to dense matrix representation. The class provides several member functions to manipulate the matrix, including the ability to add, subtract and multiply matrices.</p>

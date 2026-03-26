# COP3530 - Project 2 - Team: The Housing Crisis (Personified)

## Table of Contents
- [Project Description](#Project-Description)
  - [Purpose & Motivation](#Purpose-&-Motivation)
  - [Features](#Features)
- [Getting Started](#Getting-Started)
  - [Running the Housing Search Engine](#Running-the-Housing-Search-Engine)
  - [Running the Python Analysis](#Running-the-Python-Analysis)
- [Collaborators](#Collaborators)

## Project Description

### Purpose & Motivation
This project was created to analyze different sorting (heap sort, merge sort, and quick sort) algorithms to determine the most efficient when applied to a home-finding search engine. It includes two main parts: one for the housing search engine itself, and one for analyzing and visualizing the efficiency of the different sorting algorithms. Together, these two parts allow for a straightforward method to enter preferred future home criteria and determine the fastest method to find the best matches. 

### Features
The first part of the project takes into account home price, number of bedrooms, number of bathrooms, amount of acres, preferred city, state, zip code, and house size by square feet. It collects the user's parameters, and then prints the top five best matches sorted by whichever factor the user chooses. The second part allows users to choose between analyzing the overall performance of all parameters, or analyzing the time to run a specific field. Performance is analyzed by creating a boxplot, bar chart, or heatmap using the recorded times from each search engine run. 

## Getting Started 

### Running the Housing Search Engine
Running main.cpp pulls up the search engine; users are automatically given the choice of whether to start a new search or quit the program. Upon choosing new search, they are prompted to enter their preferred max price, city, state, zip code, minimum acre lot size, minimum house size in square feet, number of bedrooms, and number of bathrooms. The program filters by this input and prints the number of houses that meet the criteria. The user then inputs how they want the homes sorted, and the program prints the top five options. Users can choose to run again, or quit the program. 

### Running the Python Analysis
Running Visualize.py prompts the analysis part of the program. It analyzes the user's preferred part of the program (or the overall performance for all fields), and then presents it visually as either a boxplot, bar chart, or heatmap (again, chosen by the user). 

## Collaborators
Co-written by Nicole Greenberg (nicolegreenerg0321), Caitriona Schork (caitschork), Sydney Vargo (SVargo7)

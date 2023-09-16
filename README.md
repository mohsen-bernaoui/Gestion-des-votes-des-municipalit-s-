# Municipal Voting Application with GTK 2.0 and C

## Introduction

The Municipal Voting Application is a desktop software solution developed using the GTK 2.0 toolkit and the C programming language. This application facilitates the process of conducting municipal elections, allowing citizens to cast their votes securely and efficiently. This README provides an overview of the application's features, installation instructions, and basic usage guidelines.

## Features

### 1. User Authentication

- Users must log in using their credentials to ensure that only eligible voters can access the system.
- User data is securely stored and protected to prevent unauthorized access.

### 2. Candidate Information

- The application displays a list of candidates, including their names, party affiliations, and brief biographies.
- Users can browse through candidate profiles to make informed voting decisions.

### 3. Voting Interface

- The voting process is intuitive, featuring an easy-to-navigate interface.
- Voters can select their preferred candidate by clicking on their name or party symbol.

### 4. Ballot Verification

- Before finalizing their vote, users can review their selections to ensure accuracy.
- Any errors or omissions can be corrected before submitting the ballot.

### 5. Vote Submission

- Once voters are satisfied with their selections, they can submit their ballots.
- The application records each vote securely and anonymously.

### 6. Election Administration

- Election administrators have access to a backend system to manage candidates, voters, and election results.
- They can oversee the entire election process, add new candidates, and generate reports.

## Prerequisites

Before running the Municipal Voting Application, make sure you have the following software and dependencies installed:

- GTK 2.0 toolkit
- C compiler (e.g., GCC)
- SQLite database (for storing user and election data)

## Installation

Follow these steps to set up and run the Municipal Voting Application:

1. Clone the application repository to your local machine:

   ```bash
   git clone https://github.com/yourusername/municipal-voting-app.git
Navigate to the project directory:
cd municipal-voting-app

Compile the application:
gcc -o municipal_voting municipal_voting.c `pkg-config --cflags --libs gtk+-2.0` -lsqlite3

Run the application:
./municipal_voting

## Usage

1. **User Registration:** If this is your first time using the application, election administrators should create user accounts for eligible voters. This can be done through the admin backend.

2. **User Login:** Voters should log in using their credentials (username and password).

3. **Vote Casting:** Voters can browse candidate profiles and select their preferred candidate by clicking on their name or party symbol.

4. **Ballot Verification:** Before submitting the vote, users can review their selections and make any necessary changes.

5. **Vote Submission:** Once satisfied, users can submit their ballots. The application will record their vote securely and anonymously.

6. **Election Administration:** Election administrators can log in to the admin backend to monitor the election, add new candidates, and generate reports on election results.

## Contributing

If you would like to contribute to the development of this Municipal Voting Application, please follow these steps:

1. Fork the repository on GitHub.

2. Create a new branch for your feature or bug fix.

3. Make your changes and commit them.

4. Push your changes to your fork.

5. Create a pull request to merge your changes into the main repository.

## License

This Municipal Voting Application is open-source software released under the [MIT License](LICENSE). You are free to use, modify, and distribute it according to the terms of the license.

## Contact

If you have any questions or need assistance, please contact us at [your contact email or website].

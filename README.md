# Material Management Application

This is a robust and modular Material Management System developed in C++ to help organizations manage their IT inventory efficiently. The application provides tools for managing materials, users, inventory, locations, material requests, repairs, and stock monitoring.

## Features

### Material Management
- Add, modify, delete, and search for materials.
- Assign materials to specific locations.
- Monitor stock levels with alerts for critical inventory.

### User Management
- Add, modify, delete, and search for users.
- Assign access rights (read, write, etc.) to users.
- Generate inventory reports based on user departments.

### Inventory Management
- View complete material inventory.
- Generate reports by material type or department.

### Location Management
- Assign materials to locations.
- Search materials by location.

### Material Requests
- Record and display requests for materials.
- Include information like priority, user ID, and request date.

### Repairs and Maintenance
- Record repair details such as equipment ID, issue description, repair date, and history.
- Display all repair logs.

### Stock Monitoring
- Monitor inventory levels and generate alerts for low stock items.

## Technology Stack

- **Programming Language:** C++
- **Design Tool:** StarUML for class diagram and application design.
- **Object-Oriented Concepts Used:** Encapsulation, inheritance, polymorphism, and abstraction.

## Installation

1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Compile the application:
   ```bash
   g++ main.cpp -o Material Management
   ```
3. Run the application:
   ```bash
   ./Material Management
   ```

## Usage

1. Launch the application.
2. Navigate through the main menu to access different features:
   - **1:** Manage Materials
   - **2:** Manage Users
   - **3:** Manage Inventory
   - **4:** Manage Locations
   - **5:** Manage Material Requests
   - **6:** Manage Repairs
   - **7:** Monitor Stocks
   - **0:** Quit the application

## Future Enhancements

- **Authentication System:** Add secure user login and role-based access control.
- **Advanced Search:** Implement filters and advanced search features for better navigation.
- **UI Improvements:** Enhance the user interface for better usability.
- **Integration:** Expand features to include database connectivity for persistent storage.

## Contribution

Contributions are welcome! Please fork this repository, make changes, and submit a pull request.



## **Dynamic Firewall Manager**

The **Dynamic Firewall Manager** is a C++-based project that allows dynamic management of firewall rules on Linux-based systems. It enables users to add, remove, and view firewall rules programmatically using use-case-specific scenarios. This project leverages **D-Bus** for inter-process communication (IPC) to provide a flexible and efficient interface for managing firewall rules.

---

### **Features**

- **Dynamic Rule Management**:
  - Add firewall rules dynamically based on use cases.
  - Remove specific or all rules with ease.
  - View active rules currently applied to the system.
  
- **Use-Case Flexibility**:
  - Manage rules tailored to specific application or network scenarios.

- **Linux Integration**:
  - Uses Linux’s native `iptables` or `nftables` for rule management.

- **D-Bus IPC**:
  - Inter-process communication for interacting with the firewall system.
  - Allows multiple applications to request and manage firewall rules.

---

### **Requirements**

- **Operating System**: Linux (any modern distribution supporting `iptables` or `nftables`)
- **Dependencies**:
  - G++ or Clang compiler
  - CMake for build configuration
  - D-Bus development libraries (`libdbus-1-dev`)
  - `iptables` or `nftables` installed on the system

---

### **Installation**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/sidharth-sanal-01/Dynamic_Firewall.git
   cd Dynamic_Firewall
   ```

2. **Build the Project**:
   - Create a build directory:
     ```bash
     mkdir build && cd build
     ```
   - Configure the project with CMake:
     ```bash
     cmake ..
     ```
   - Compile the project:
     ```bash
     make
     ```

3. **Install**:
   - Run the following command to install the binary (optional):
     ```bash
     sudo make install
     ```

---

### **Usage**

#### **1. Running the Firewall Manager**
Start the application from the terminal:
```bash
./DynamicFirewall 
```

### **Architecture**

#### **Core Components**:
1. **Rule Manager**:
   - Implements logic for adding, removing, and listing firewall rules.
   - Interfaces with `iptables` or `nftables` commands.

2. **D-Bus IPC**:
   - Provides an IPC layer for communication.
   - Exposes APIs for external applications to interact with the firewall.

3. **CLI Interface**:
   - User-friendly command-line interface for managing rules.
   - Parses and executes user commands.

---


### **Contributing**

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a feature branch:
   ```bash
   git checkout -b feature-name
   ```
3. Commit your changes and push the branch:
   ```bash
   git push origin feature-name
   ```
4. Submit a pull request.

---

### **License**

This project is licensed under the **Private License**. See the `LICENSE` file for more details.

---

### **Contact**

For questions, issues, or feature requests, please contact:
- **Email**: sidharthsanal02@gmail.com.com
- **GitHub**: [https://github.com/sidharth-sanal-01](https://github.com/sidharth-sanal-01)
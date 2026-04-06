# digital-library-genre-tree-crud

# 📚 Digital Library – Genre Management using Binary Search Tree (CRUD)

## 👥 Team Members:

- Name 1: Varshini
- Name 2: Manojna

---

## 🎯 Problem Statement


Managing genres in a digital library requires efficient storage, searching, and modification. This project uses a **Binary Search Tree (BST)** to organize and manage genres with CRUD operations.

---

## 🌍 Real-World Application


- Digital Libraries (Kindle, Google Books)
- Library Management Systems
- Online Book Stores
- Category-based Recommendation Systems

---

## 🧩 Data Structure Used

### Binary Search Tree (BST)

- Left subtree → smaller values
- Right subtree → larger values
- Efficient searching, insertion, deletion

---

## ⚙️ Features (CRUD Operations)

### ✅ Create
- Add new genre into the tree

### 📖 Read
- Display all genres (Inorder Traversal)

### ✏️ Update
- Modify existing genre name

### ❌ Delete
- Remove a genre from the tree

### 🔍 Search
- Find a genre in the tree

---

## 🧠 Algorithm

### Insert
1. Compare with root
2. Go left or right
3. Insert at correct position

### Search
1. Compare value
2. Traverse left or right

### Delete
1. Node with 0 children → remove directly
2. Node with 1 child → replace node
3. Node with 2 children → replace with inorder successor

### Display
- Inorder traversal (sorted output)

---

## 💻 Technologies Used
- Language: C
- Compiler: GCC
- Concepts: Pointers, Dynamic Memory Allocation, Recursion

---

## 🏗️ Project Structure

Digital-Library-Genre-Tree-CRUD/

│
├── src/
│ └── main.c
│
├── docs/
│ └── project_report.pdf
│
├── ppt/
│ └── presentation.pptx
│
├── README.md
├── sample_output_bst.txt


---

## ▶️ Compilation & Execution

### Compile

```bash
gcc main.c -o project

Run
./project

# Autocomplete and Spell Checker (C++)

A command-line based autocomplete and spell checker application implemented using the **Trie data structure**.
The program provides prefix-based word suggestions and recommends the closest matching words using
**Edit Distance (Levenshtein Distance)** when no exact match is found.

---

## Features

- Prefix-based autocomplete using Trie
- Spell checking with closest word suggestions
- Suggests top 3 nearest words based on edit distance
- Allows users to add new words dynamically
- Persistent dictionary using file handling
- Simple and interactive CLI interface

---

## 📁 Project Structure


├── data

│ └── words.txt

├── src

│ ├── main.cpp

│ └── main.exe

├── .gitignore

└── README.md

---


## Technologies_used:
  - C++
  - Trie Data Structure
  - Levenshtein (Edit Distance) Algorithm
  - STL:
      - vector
      - map
      - algorithm
  - File Handling

---

## How_it_works:
  - Words from data/words.txt are loaded into a Trie
  - User enters a word or prefix
  - If matches exist, autocomplete suggestions are shown
  - If no match exists, closest words are suggested using edit distance
  - Users can add new words to the dictionary dynamically

---


## How_to_run:

  ### Compile:
  ```bash
    - cd src
    - g++ main.cpp -o main

```
  ### Run:
  ```bash
    - ./main

```
  note: Ensure data/words.txt exists relative to the project root

## Sample_output:
  - "✨ autocomplete + spell check ✨"
  - "enter word or prefix (exit to quit): app"
  - "found:"
  - "➤ apple"
  - "➤ application"
  - "➤ apply"

---

## Learning_outcomes:
  - Implemented Trie-based searching for fast autocomplete
  - Applied edit distance algorithm for spell correction
  - Used recursion and DFS for word traversal
  - Gained hands-on experience with file I/O in C++
  - Practiced clean project structure and Git usage

---

 ## Author:
  name: Lavanya Agrawal

## Future_improvements:
  - Case-insensitive search
  - Limit suggestions using priority queues
  - Improve performance for large dictionaries
  - Add unit tests

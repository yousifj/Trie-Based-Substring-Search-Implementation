# Trie-Based Substring Search Implementation

A robust implementation of a Trie data structure for efficient substring searching and word storage, with support for case-insensitive matching and alphabetic characters.

## 📋 Overview

This project implements a Trie (prefix tree) that allows for efficient storage and retrieval of strings, along with substring matching capabilities. The implementation supports case-insensitive matching and handles alphabetic characters (a-z).

## 🚀 Features

- Case-insensitive word storage and retrieval
- Substring matching across all stored words
- Support for alphabetic characters (a-z)
- Multiple testing modes (manual, preset fruits list, preset names list)
- Efficient prefix-based search operations

## 🛠️ Building and Running

### Prerequisites
- C++ compiler
- Make build system

### Build Instructions

#### Unix/Linux/macOS:
```bash
make
./countsubstrings
```

#### Windows (MinGW):
```bash
mingw32-make
./countsubstrings
```

## 📖 Usage Guide

The program offers three testing modes:

### 1. Manual Test Mode
```
1. Add words to the trie
2. Search for specific words
3. Find words containing a substring
```

### 2. Fruits Test Mode
- Pre-populated with a comprehensive list of fruit names
- Test substring matching within fruit names

### 3. Names Test Mode
- Pre-populated with a list of common names
- Test substring matching within names

## 💡 Example Usage

### Manual Mode Example:
```
Enter test mode (1-3): 1

# Adding words:
> yousif
> martin
> john
> alex

# Finding words:
> yousif
"yousif" Exists in the tree
> jackson
"jackson" Does not exist in the tree

# Finding substrings:
> i
Number of words containing the substring: 2
martin
yousif
```

### Fruits Mode Example:
```
Enter test mode (1-3): 2

Input substring to search: app
Number of words containing the substring: 2
apple
pineapple
```

### Names Mode Example:
```
Enter test mode (1-3): 3

Input substring to search: ma
Number of words containing the substring: 4
emma
madison
matthew
thomas
```

## 📝 Implementation Notes

- Words are automatically converted to lowercase for consistency
- Only alphabetic characters (a-z) are accepted
- Duplicate words are automatically handled (counted once)
- Special characters are not supported and may cause unexpected behavior

## 📊 Sample Data

### Included Datasets:
1. **Fruits Dataset**: 70+ fruit names including common and exotic fruits
2. **Names Dataset**: 60+ common first names

## ⚠️ Limitations

- Only supports alphabetic characters (a-z)
- Case-sensitive input is automatically converted to lowercase
- Special characters are not supported
- Duplicate entries are counted only once

## 🧪 Testing

The program includes three testing modes:
1. Manual testing for custom input
2. Predefined fruits dataset testing
3. Predefined names dataset testing

Each mode allows for:
- Word existence verification
- Substring matching across all stored words
- Case-insensitive search operations

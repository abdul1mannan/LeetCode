name: Sort Table

on:
  push:
    branches:
      - main  # Adjust branch name if needed
  pull_request:
    branches:
      - main  # Adjust branch name if needed

jobs:
  sort-table:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout repository
      uses: actions/checkout@v4

    - name: Install Python
      uses: actions/setup-python@v2
      with:
        python-version: '3.x'

    - name: Install dependencies
      run: pip install pandas  # Assuming you use pandas for sorting
      
    - name: Install dependencies
      run: pip install pandas tabulate

    - name: Sort table
      run: python sort_table.py

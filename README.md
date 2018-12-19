# Meeting-Manager

This program applies OOP principles to create a tool for managing meetings.

Supported operations include displaying all meetings in calendar in sorted order
of keyword, displaying all keywords in each level of the tree, displaying all
meetings for a specific keyword, posting a new meeting and responding to a
posted meeting. External data file is used to load and write data.

The data structure used is a red-black balanced tree, which is sorted by 
a keyword for each node. Each node of the tree contains all meetings associated
with that specific keyword.

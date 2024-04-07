# list inputs
inputs = list(map(int, input().split()))

thislist = ["apple", "banana", "cherry"]
thislist.append("orange")
thislist.pop()
x = len(thislist)

thislist.sort()
print(thislist)
thislist.sort(reverse=True)
print(thislist)

mylist = thislist.copy()
# --------------------------------------------------------------
# 2D array

rows, cols = (5, 5)
arr = [[0]*cols]*rows

# Sample 2D list
matrix = [
    [1, 3, 5],
    [1, 2, 8],
    [7, 6, 9]
]

# Sort based on the first column (index 0) and then the second column (index 1)
sorted_matrix = sorted(matrix, key=lambda x: (x[0], -x[1]))

print(sorted_matrix)

# ---------------------------------------------------------


# Set

thisset = {"apple", "banana", "cherry"}

thisset.add("orange")
thisset.remove("apple")
thisset.remove("aaa")
thisset.discard("aaa")
# remove will raise error if not present
print(thisset)
if("apple" in thisset):
  print(1)
else:
  print(0)
if("orange" in thisset):
  print(1)
else:
  print(0)


thisset = sorted(thisset)
for x in thislist:
  a = x
  print(a)


# --------------------------------------------------

#Map

thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict.pop("model")


# ------------------------------------------------------------------  

#Funct

def my_function():
  print("Hello from a function")

# -----------------------------------------------------------------------
# first ele ascending and sec ele descending
def custom_sort(data):
  """
  Sorts a list of tuples based on the first element (ascending) and second element (descending).

  Args:
      data: A list of tuples.

  Returns:
      A new list containing the sorted tuples.
  """
  return sorted(data, key=lambda x: (-x[1], x[0]))

# Sample data
data = [(1, 8), (1, 5), (2, 2), (4, 1)]

# Sort the data using the custom function
sorted_data = custom_sort(data.copy())

print(sorted_data)  # Output: [(1, 5), (2, 2), (3, 8), (4, 1)]

# ----------------------------------------------------------




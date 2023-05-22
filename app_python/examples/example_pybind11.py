import os, sys


def main():
    # Add the path to the pybind11 module
    sys.path.append(os.path.join(os.path.dirname(__file__), '..', '..'))
    import pybind11_example

    # Call the function
    pybind11_example.print_hello()

if     
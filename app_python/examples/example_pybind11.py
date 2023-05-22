import os, sys


def main():
    # Add the path to the pybind11 module
    sys.path.append(os.path.join(os.path.dirname(__file__), '..', '..'))

    # Call the function

if __name__ == '__main__':
    main()
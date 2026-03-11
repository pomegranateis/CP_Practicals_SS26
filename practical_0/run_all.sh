#!/bin/bash

# Script to compile and run all C++ files in practical_0

echo "=== Running all C++ programs in practical_0 ==="
echo

# Create outputs directory if it doesn't exist
mkdir -p outputs

# Loop through all C++ files
for i in {01..10}
do
    cpp_file="q$i.cpp"
    exe_file="q$i"
    
    echo "----------------------------------------"
    echo "Processing $cpp_file"
    echo "----------------------------------------"
    
    # Check if the C++ file exists
    if [ -f "$cpp_file" ]; then
        echo "Compiling $cpp_file..."
        
        # Compile the C++ file
        if g++ -o "$exe_file" "$cpp_file"; then
            echo "✓ Compilation successful"
            echo "Running $exe_file:"
            echo
            
            # Run the executable
            ./"$exe_file"
            
            echo
            echo "✓ Execution completed"
        else
            echo "✗ Compilation failed for $cpp_file"
        fi
    else
        echo "✗ File $cpp_file not found"
    fi
    
    echo
done

echo "=== All programs processed ==="

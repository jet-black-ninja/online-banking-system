# input the name of the output file
OUTPUT_EXECUTABLE="output/OBS"

# Compile the C++ code
echo "compiling ..."
g++ -g -o "$OUTPUT_EXECUTABLE" main.cpp

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./"$OUTPUT_EXECUTABLE"
else
    echo "Compilation failed."
fi
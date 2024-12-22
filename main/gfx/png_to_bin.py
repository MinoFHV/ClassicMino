# Path to the source PNG file in the 'src' folder
input_png_path = "src/testy.png"

# Open the PNG image in binary read mode
with open(input_png_path, "rb") as png_file:
    png_data = png_file.read()

# Path to save the binary data in the 'src' folder
output_bin_path = "src/testy.bin"

# Write the binary data to a .bin file
with open(output_bin_path, "wb") as bin_file:
    bin_file.write(png_data)

print(f"PNG image has been successfully saved as {output_bin_path}")

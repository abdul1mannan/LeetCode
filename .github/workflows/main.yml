import pandas as pd

# Read the README.md file
with open('README.md', 'r') as file:
    content = file.read()

# Split the content into lines
lines = content.split('\n')

# Extract table data
table_data = [line.split('|')[1:-1] for line in lines[1:-1]]

# Convert to DataFrame
df = pd.DataFrame(table_data, columns=['No.', 'Title', 'Solution', 'Difficulty'])

# Function to convert a value to integer if possible, otherwise return None
def try_convert_to_int(value):
    try:
        return int(value.strip('[]'))
    except (ValueError, AttributeError):
        return None

# Apply the function to the 'No.' column
df['No.'] = df['No.'].apply(try_convert_to_int)

# Remove rows with None values in the 'No.' column
df = df.dropna(subset=['No.'])

# Sort DataFrame by 'No.'
df_sorted = df.sort_values(by='No.')

# Convert DataFrame back to Markdown table
markdown_table = df_sorted.to_markdown(index=False, tablefmt='github')

# Debug: Print the Markdown table
print("Markdown table:")
print(markdown_table)

# Update README.md file with sorted Markdown table
with open('README.md', 'w') as file:
    file.write(markdown_table + '\n')

# Debug: Print confirmation message
print("README.md file updated successfully!")

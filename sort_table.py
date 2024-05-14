import pandas as pd

# Read the README.md file
with open('README.md', 'r') as file:
    content = file.read()

# Split the content into lines
lines = content.split('\n')

# Extract table data
table_data = [line.split('|')[1:-1] for line in lines[1:-1]]

# Convert to DataFrame
df = pd.DataFrame(table_data, columns=['#', 'Title', 'Solution', 'Difficulty'])

# Sort DataFrame by #
df_sorted = df.sort_values(by='#')

# Convert DataFrame back to Markdown table
markdown_table = df_sorted.to_markdown(index=False, tablefmt='github')

# Update README.md file
with open('README.md', 'w') as file:
    file.write(lines[0] + '\n' + markdown_table + '\n' + lines[-1])

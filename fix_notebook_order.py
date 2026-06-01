import json

# Load the notebook
notebook_path = r"TMDb_Movie_Analysis.ipynb"

with open(notebook_path, 'r') as f:
    notebook = json.load(f)

# Reverse the cells to correct the order
notebook['cells'].reverse()

# Save the corrected notebook
with open(notebook_path, 'w') as f:
    json.dump(notebook, f, indent=1)

print("✓ Notebook cells reordered successfully!")
print(f"✓ Total cells: {len(notebook['cells'])}")

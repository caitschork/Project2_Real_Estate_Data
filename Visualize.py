import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# 1. Load the data from your C++ program
try:
    df = pd.read_csv('sort_results.csv')

    # 2. Set the visual style
    sns.set_theme(style="whitegrid")
    plt.figure(figsize=(10, 6))

    # 3. Create the bar plot
    plot = sns.barplot(x='Algorithm', y='Time', data=df, palette='viridis')

    # 4. Add labels and title
    plt.title('Sorting Algorithm Performance: Heap vs Merge', fontsize=16)
    plt.ylabel('Execution Time (ms)', fontsize=12)
    plt.xlabel('Algorithm', fontsize=12)

    # Add data labels on top of bars
    for p in plot.patches:
        plot.annotate(format(p.get_height(), '.2f'),
                      (p.get_x() + p.get_width() / 2., p.get_height()),
                      ha = 'center', va = 'center',
                      xytext = (0, 9),
                      textcoords = 'offset points')

    plt.show()

except FileNotFoundError:
    print("Error: sort_results.csv not found. Run the C++ program first!")

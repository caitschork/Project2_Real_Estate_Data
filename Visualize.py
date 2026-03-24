import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


try:
    df = pd.read_csv('sort_results.csv')

    #visual style
    sns.set_theme(style="whitegrid")
    plt.figure(figsize=(10, 6))

    #boxplot to show distribution of runtimes
    sns.boxplot(x='Algorithm', y='Time', data=df)

    #labels
    plt.title('Runtime distribution per algorithm', fontsize=16)
    plt.ylabel('Execution Time (ms)', fontsize=12)
    plt.xlabel('Algorithm', fontsize=12)

    # # Add data labels on top of bars
    # for p in plot.patches:
    #     plot.annotate(format(p.get_height(), '.2f'),
    #                   (p.get_x() + p.get_width() / 2., p.get_height()),
    #                   ha = 'center', va = 'center',
    #                   xytext = (0, 9),
    #                   textcoords = 'offset points')

    plt.show()

except FileNotFoundError:
    print("Error: sort_results.csv not found. Run the C++ program first!")

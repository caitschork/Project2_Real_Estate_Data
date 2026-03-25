import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

def main():
    try:
        #Load CSV
        df = pd.read_csv('sort_results.csv')
        if 'Field' not in df.columns:
            raise ValueError("CSV must have a 'Field' column.")

        sns.set_theme(style="white")
        box_color = "##cdb4db"

        while True:
            #Field selection
            available_fields = df['Field'].unique().tolist()
            print("\nSelect a field to analyze:")
            print("0. Total Performance (all fields)")
            for i, f in enumerate(available_fields, start=1):
                print(f"{i}. {f}")
            choice = input("Enter your choice number (or 'q' to quit): ").strip()

            if choice.lower() == 'q':
                print("Exiting dashboard.")
                break

            if not choice.isdigit() or int(choice) < 0 or int(choice) > len(available_fields):
                print("Invalid choice. Defaulting to 'Total Performance'.")
                df_field = df
                field = "Total Performance"
            else:
                choice_num = int(choice)
                if choice_num == 0:
                    df_field = df
                    field = "Total Performance"
                else:
                    field = available_fields[choice_num - 1]
                    df_field = df[df['Field'] == field]

            #Graph selection
            print("\nSelect the type of graph to generate:")
            print("1. Boxplot")
            print("2. Bar Chart")
            print("3. Heatmap (all fields)")
            graph_choice = input("Enter choice number: ").strip()

            if graph_choice == "1":
                # Boxplot
                plt.figure(figsize=(12, 6))
                sns.boxplot(
                    x='Algorithm',
                    y='Time',
                    data=df_field,
                    color=box_color,
                    boxprops=dict(facecolor=box_color, edgecolor='black', alpha=0.6),
                    medianprops=dict(color='black', linewidth=2),
                    whiskerprops=dict(color='black', linewidth=1.5),
                    capprops=dict(color='black', linewidth=1.5),
                    flierprops=dict(marker='o', color='black', alpha=0.5)
                )
                plt.title(f'Runtime Distribution for {field}', fontsize=16, weight='bold')
                plt.ylabel('Execution Time (ms)')
                plt.xlabel('Algorithm')
                sns.despine()
                plt.show()

            elif graph_choice == "2":
                # Bar chart
                avg_time = df_field.groupby('Algorithm')['Time'].mean().reset_index()
                plt.figure(figsize=(8, 5))
                sns.barplot(x='Algorithm', y='Time', data=avg_time, color=box_color, edgecolor='black')
                plt.title(f'Average Runtime for {field}', fontsize=16, weight='bold')
                plt.ylabel('Average Time (ms)')
                plt.xlabel('Algorithm')
                sns.despine()
                plt.show()

            elif graph_choice == "3":
                # Heatmap
                pivot = df.pivot_table(index='Algorithm', columns='Field', values='Time', aggfunc='mean')
                plt.figure(figsize=(10, 6))
                sns.heatmap(pivot, annot=True, fmt=".2f", cmap="Blues", cbar_kws={'label': 'Avg Runtime (ms)'})
                plt.title('Average Runtime per Algorithm across All Fields', fontsize=16, weight='bold')
                plt.ylabel('Algorithm')
                plt.xlabel('Field')
                plt.show()
            else:
                print("Invalid graph choice. No graph generated.")

    except FileNotFoundError:
        print("Error: sort_results.csv not found. Run the C++ program first!")
    except ValueError as ve:
        print(ve)

if __name__ == "__main__":
    main()

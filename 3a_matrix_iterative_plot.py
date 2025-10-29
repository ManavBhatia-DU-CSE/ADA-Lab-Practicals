import matplotlib.pyplot as plt


x = [2, 4, 8, 16]  
y = [0.000000, 0.002000, 0.026000, 0.149000]

plt.figure(figsize=(10, 6))

plt.plot(
    x, y,
    color='red',
    linestyle='-',
    linewidth=2.5,
    marker='o',
    markersize=8,
    markerfacecolor='yellow',
    markeredgecolor='black',
)

plt.title("Execution Time of Iterative Matrix Multiplication", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Matrix Size (n × n)", fontsize=12, color='purple')
plt.ylabel("Execution Time (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()

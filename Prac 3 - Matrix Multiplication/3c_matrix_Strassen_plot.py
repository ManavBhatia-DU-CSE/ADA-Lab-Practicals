import matplotlib.pyplot as plt

x = [2, 4, 8, 16]  
y = [0.003000, 0.027000, 0.149000, 1.065000]

plt.figure(figsize=(10, 6))

plt.plot(
    x, y,
    color='green',
    linestyle='-',
    linewidth=2.5,
    marker='^',
    markersize=8,
    markerfacecolor='orange',
    markeredgecolor='black',
)

plt.title("Execution Time of Strassen Matrix Multiplication", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Matrix Size (n × n)", fontsize=12, color='purple')
plt.ylabel("Execution Time (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()

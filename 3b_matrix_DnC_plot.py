import matplotlib.pyplot as plt

x = [2, 4, 8, 16]  
y = [0.003000, 0.024000, 0.095000, 0.784000] 

plt.figure(figsize=(10, 6))

plt.plot(
    x, y,
    color='blue',
    linestyle='-',
    linewidth=2.5,
    marker='s',
    markersize=8,
    markerfacecolor='lightgreen',
    markeredgecolor='black',
)

plt.title("Execution Time of Divide & Conquer Matrix Multiplication", fontsize=16, fontweight='bold', color='darkblue')
plt.xlabel("Matrix Size (n × n)", fontsize=12, color='purple')
plt.ylabel("Execution Time (seconds)", fontsize=12, color='purple')

plt.grid(True)
plt.show()
import matplotlib.pyplot as plt
import numpy as np

# Read the file "first.txt"
with open("Tres_bucles.txt", "r") as f:
    data = f.read().splitlines()  # Lee las líneas sin el salto de línea extra
    y = list(map(int, data))      # Convierte las cadenas de texto en enteros

# Read the file "second.txt"
with open("Bloques.txt", "r") as s:
    data1 = s.read().splitlines()
    y1 = list(map(int, data1))    # Convierte las cadenas de texto en enteros

# Create the x axis (assuming 100 points in the files)
x = np.arange(0, 10, 1)

# Plot the graph
plt.plot(x, y, label="Three loops", marker='o')   # Se añaden marcadores para mayor claridad
plt.plot(x, y1, label="Blocks", marker='x')

# Add labels and title
plt.xlabel("# of data")
plt.ylabel("Time (microseconds)")  # Ajusta la etiqueta para reflejar los valores de tiempo
plt.title("Comparison of Execution Times")

# Set y-axis limits for better scaling
plt.ylim(0, max(max(y), max(y1)) + 100000)  # Aumenta un pequeño margen en el eje y

# Add legend and grid
plt.legend()
plt.grid(True)

plt.savefig('comparation_2.png')

plt.show()
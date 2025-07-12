import numpy as np
import matplotlib.pyplot as plt
import random
from PIL import Image

# Step 1: Load the given image (Cherry.jpg) and convert to grayscale
def rgb_to_grayscale(image):
    return np.dot(image[..., :3], [0.2989, 0.5870, 0.1140])

# Load the image using PIL and convert to a numpy array
image = np.array(Image.open('Cherry.jpg'))

# Convert the loaded image to grayscale
gray_image = rgb_to_grayscale(image)

plt.figure(figsize=(10, 5))
plt.subplot(1, 2, 1)
plt.title('Original Image')
plt.imshow(image)
plt.axis('off')

plt.subplot(1, 2, 2)
plt.title('Grayscale Image')
plt.imshow(gray_image, cmap='gray')
plt.axis('off')
plt.show()

# Step 2: Add White Gaussian Noise with different std deviations
def add_gaussian_noise(image, std_dev):
    noise = np.random.normal(0, std_dev, image.shape)
    noisy_image = image + noise
    return np.clip(noisy_image, 0, 255)  # Ensure the values remain in the 0-255 range

std_devs = [1, 10, 30, 50]
plt.figure(figsize=(10, 10))
for i, std in enumerate(std_devs, 1):
    noisy_image = add_gaussian_noise(gray_image, std)
    plt.subplot(2, 2, i)
    plt.title(f'Gaussian Noise (std={std})')
    plt.imshow(noisy_image, cmap='gray')
    plt.axis('off')
plt.show()

# Step 3: Add Salt and Pepper Noise
def add_salt_and_pepper_noise(image, amount):
    noisy_image = image.copy()
    num_salt = np.ceil(amount * image.size * 0.5)
    num_pepper = np.ceil(amount * image.size * 0.5)

    # Add salt (white pixels)
    for _ in range(int(num_salt)):
        i = random.randint(0, image.shape[0] - 1)
        j = random.randint(0, image.shape[1] - 1)
        noisy_image[i, j] = 255

    # Add pepper (black pixels)
    for _ in range(int(num_pepper)):
        i = random.randint(0, image.shape[0] - 1)
        j = random.randint(0, image.shape[1] - 1)
        noisy_image[i, j] = 0

    return noisy_image

amounts = [0.1, 0.3]
plt.figure(figsize=(10, 5))
for i, amount in enumerate(amounts, 1):
    sp_image = add_salt_and_pepper_noise(gray_image, amount)
    plt.subplot(1, 2, i)
    plt.title(f'Salt & Pepper Noise ({int(amount * 100)}%)')
    plt.imshow(sp_image, cmap='gray')
    plt.axis('off')
plt.show()

# Step 4: Implement Box Filter, Median Filter, and Gaussian Filter
def box_filter(image, kernel_size=3):
    pad_size = kernel_size // 2
    padded_image = np.pad(image, pad_size, mode='constant', constant_values=0)
    filtered_image = np.zeros_like(image)
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i:i+kernel_size, j:j+kernel_size]
            filtered_image[i, j] = np.mean(region)
    return filtered_image

def median_filter(image, kernel_size=3):
    pad_size = kernel_size // 2
    padded_image = np.pad(image, pad_size, mode='constant', constant_values=0)
    filtered_image = np.zeros_like(image)
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i:i+kernel_size, j:j+kernel_size]
            filtered_image[i, j] = np.median(region)
    return filtered_image

def gaussian_filter(image, kernel_size=3, sigma=1):
    pad_size = kernel_size // 2
    padded_image = np.pad(image, pad_size, mode='constant', constant_values=0)
    filtered_image = np.zeros_like(image)
    
    # Create Gaussian kernel
    ax = np.arange(-pad_size, pad_size+1)
    xx, yy = np.meshgrid(ax, ax)
    kernel = np.exp(-(xx**2 + yy**2) / (2 * sigma**2))
    kernel /= np.sum(kernel)
    
    # Apply convolution
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            region = padded_image[i:i+kernel_size, j:j+kernel_size]
            filtered_image[i, j] = np.sum(region * kernel)
    return filtered_image

# Use a noisy image for testing (Gaussian noise with std=50)
noisy_image = add_gaussian_noise(gray_image, 50)

# Apply filters with kernel size 3x3
filtered_box = box_filter(noisy_image, kernel_size=3)
filtered_median = median_filter(noisy_image, kernel_size=3)
filtered_gaussian = gaussian_filter(noisy_image, kernel_size=3)

plt.figure(figsize=(15, 5))
plt.subplot(1, 4, 1)
plt.title('Noisy Image')
plt.imshow(noisy_image, cmap='gray')
plt.axis('off')

plt.subplot(1, 4, 2)
plt.title('Box Filter (3x3)')
plt.imshow(filtered_box, cmap='gray')
plt.axis('off')

plt.subplot(1, 4, 3)
plt.title('Median Filter (3x3)')
plt.imshow(filtered_median, cmap='gray')
plt.axis('off')

plt.subplot(1, 4, 4)
plt.title('Gaussian Filter (3x3)')
plt.imshow(filtered_gaussian, cmap='gray')
plt.axis('off')
plt.show()

# Step 5: Vary kernel sizes and observe effects
kernel_sizes = [5, 10]
for k in kernel_sizes:
    filtered_box = box_filter(noisy_image, kernel_size=k)
    filtered_median = median_filter(noisy_image, kernel_size=k)
    filtered_gaussian = gaussian_filter(noisy_image, kernel_size=k)

    plt.figure(figsize=(15, 5))
    plt.subplot(1, 3, 1)
    plt.title(f'Box Filter ({k}x{k})')
    plt.imshow(filtered_box, cmap='gray')
    plt.axis('off')

    plt.subplot(1, 3, 2)
    plt.title(f'Median Filter ({k}x{k})')
    plt.imshow(filtered_median, cmap='gray')
    plt.axis('off')

    plt.subplot(1, 3, 3)
    plt.title(f'Gaussian Filter ({k}x{k})')
    plt.imshow(filtered_gaussian, cmap='gray')
    plt.axis('off')
    plt.show()

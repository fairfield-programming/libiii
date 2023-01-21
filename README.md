# !(https://github.com/fairfield-programming/libiii/raw/master/.github/banner.png)[libiii]

An embeddable library for the Interpolated Image Interchange format.

## Usage

Libiii is designed to be an embeddable library enabling the parsing, creation, and rendering of Roman files (files using the [Interpolated Image Interchange Format](https://vault.fairfieldprogramming.org/standards/roman-format)). This library is made to be simple to use and integrate into modern apps. Because of this, we designed the library to be very high-level. But, we still allow anyone to access the lower level functions.

We encourage all apps to utilize the Roman Format as it can lead to lower file sizes, more efficient transmissions, video, 3D graphics, and other advanced features. Since the format itself is so complex and modular, we do encourage usage of this library, as it always stays up to date with the format.

### Porting

We love and encourage ports of this library over to other languages. To keep the ports high quality and up to date, please have them depend on this repository in some kind of way. On top of this, check if a library exists already before creating a new one– we want to prevent overcrowding in the Roman Format ecosystem.

### Embedding

This library can be compiled as a dynamic or static library depending on your preference. The files for the library are included in the releases section of this Github page.

## Contributing

We love contributions to the project, but do ask that they be high quality and reflect our core principles of simplicity, speed, and maintainability. We have found that code with comments has a much higher chance of being integrated into the project. On top of this, the most performant code is usually using the simplest solution. So, we do ask that you avoid overly complex performance optimizations (though we do judge them on a case by case basis, so do ask).

## API

### Architecture

We separate libraries based on their usage. Doing this will hopefully prevent bloating as the number of features begin to increase in the specification as a whole.

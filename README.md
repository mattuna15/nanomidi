# nanomidi

Nanomidi is a simple stream-based MIDI message encoder and decoder written in C.
It is suitable for embedded (microcontroller) applications.

For more information, see [API documentation][1] (generated by Doxygen) or
examples.

## Scope

Implemented:

 - [Message encoder][2] `midi_encode()`
 - [Message decoder][3] `midi_decode()` with support for **Running Status**
   (omitted status byte in successive messages of the same type)
 - [Data structures][4] for **Channel Mode Messages** (Note On, Control Change,
   etc.) and **System Common Messages**
 - Support for **System Real Time Messages** (single-byte messages which can
   occur anywhere in the stream)
 - Support for **System Exclusive Messages** (SysEx)
 - Support for USB MIDI packet format (`midi_encode_usb()` and
   `midi_decode_usb()`) described in
   [Universal Serial Bus Device Class Definition for MIDI Devices][6]

## Examples

To build examples, simply run `make` in the `examples` directory.

Example `example-libusb` requires [libusb][5]. On Ubuntu, install it using

	sudo apt-get install libusb-1.0-0-dev

## License

Nanomidi is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

See file `COPYING` for details.

[1]: https://doc.adamh.cz/nanomidi
[2]: https://doc.adamh.cz/nanomidi/group__encoder.html
[3]: https://doc.adamh.cz/nanomidi/group__decoder.html
[4]: https://doc.adamh.cz/nanomidi/structmidi__message.html
[5]: http://libusb.info/
[6]: https://www.usb.org/sites/default/files/midi10.pdf

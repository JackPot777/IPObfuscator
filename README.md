# IPObfuscator

A simple tool to convert the IP to different obfuscated forms.

It's a remastered version of [Osanda's IPObfuscator](https://github.com/OsandaMalith/IPObfuscator)
with patch from [1lastBr3ath](https://github.com/1lastBr3ath).

IPObfuscator now can be useful to create a wordlist of obfuscated IP's for ... your needs.
Also it allows custom prefix and postfix for IP address.

## Usage

```
 ---------------------------------------------------------------------
                 Welcome to IPObfuscator                              
                                                                      
  Coded by       @OsandaMalith  (http://osandamalith.wordpress.com)   
                 @1lastBr3ath   (http://cm2.pw)                       
  Remastered by  @chinarulezzz  (https://github.com/chinarulezzz)     
 ---------------------------------------------------------------------
Usage: ./ip <ip> [prefix] [postfix]
```
## Example

Create obfuscated IP addresses for testing, for example, a bogon filtering:

```
./ip 127.0.0.1 https://

https://2130706433
https://0x7F000001
https://017700000001
https://0x7F.0x00.0x00.0x01
https://0177.0000.0000.0001
https://0x000000007F.0x0000000000.0x0000000000.0x0000000001
https://0000000177.0000000000.0000000000.0000000001
https://0x7F.0x00.0x00.1
https://0x7F.0x00.0.1
https://0x7F.0.0.1
https://0177.0000.0000.1
https://0177.0000.0.1
https://0177.0.0.1
https://0x7F.0x00.1
https://0177.0000.1
https://0x7F.0000.1
https://0x7F.1
https://0177.1
https://0x7F.0x00.0000.0001
https://0x7F.0000.0000.0001
https://0x7F.0000.1
```

# Credits

- Osanda Malith Jayathissa (https://github.com/OsandaMalith)

- 1lastBr3ath              (https://github.com/1lastBr3ath)

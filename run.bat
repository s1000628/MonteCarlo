@echo off
for /l %%n in (1, 1, 20) do "Release/MonteCarlo.exe" %%n > "Result/%%n.csv"

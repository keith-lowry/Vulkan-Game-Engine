$buildFolder = "$PWD\build"
$srcFolder = "$PWD\src"
$pre = ">"
$shaders = "simple_shader.vert", "simple_shader.frag"

Write-Host "$pre Compiling Shaders..."
New-Item -ItemType Directory -Force -Path $PWD\build\shaders | Out-Null # make shaders folder
Write-Host "-- Created .\build\shaders"

foreach ($name in $shaders) {
    $outName = "$buildFolder\shaders\$name.spv"
    glslc.exe $srcFolder\shaders\$name -o $outName
    Write-Host "-- $name ✔"
}
Write-Host "-- Shader binaries written to: $buildFolder\shaders"

Write-Host "$pre Running CMake..."
cmake -G "MinGW Makefiles" -S $srcFolder -B $buildFolder

Write-Host "$pre Compiling Binary... "
cd .\build
make
cd ..\
Write-Host "$pre Done!"

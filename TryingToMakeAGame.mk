##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TryingToMakeAGame
ConfigurationName      :=Debug
WorkspacePath          :=/home/naufal/Dokumen/Projects/TryingToMakeAGame/TryingToMakeAGame
ProjectPath            :=/home/naufal/Dokumen/Projects/TryingToMakeAGame
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Naufal Adriansyah
Date                   :=20/06/21
CodeLitePath           :=/home/naufal/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="TryingToMakeAGame.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./include/ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)glfw3 $(LibrarySwitch)dl $(LibrarySwitch)Xrandr $(LibrarySwitch)X11 $(LibrarySwitch)pthread 
ArLibs                 :=  "glfw3" "dl" "Xrandr" "X11" "pthread" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/MeshRenderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Camera.cpp$(ObjectSuffix) $(IntermediateDirectory)/Main.cpp$(ObjectSuffix) $(IntermediateDirectory)/LightRenderer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Shader.cpp$(ObjectSuffix) $(IntermediateDirectory)/glad.c$(ObjectSuffix) $(IntermediateDirectory)/TextureLoader.cpp$(ObjectSuffix) $(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/MeshRenderer.cpp$(ObjectSuffix): MeshRenderer.cpp $(IntermediateDirectory)/MeshRenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/MeshRenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MeshRenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MeshRenderer.cpp$(DependSuffix): MeshRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MeshRenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MeshRenderer.cpp$(DependSuffix) -MM MeshRenderer.cpp

$(IntermediateDirectory)/MeshRenderer.cpp$(PreprocessSuffix): MeshRenderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MeshRenderer.cpp$(PreprocessSuffix) MeshRenderer.cpp

$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix): Camera.cpp $(IntermediateDirectory)/Camera.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/Camera.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Camera.cpp$(DependSuffix): Camera.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Camera.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Camera.cpp$(DependSuffix) -MM Camera.cpp

$(IntermediateDirectory)/Camera.cpp$(PreprocessSuffix): Camera.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Camera.cpp$(PreprocessSuffix) Camera.cpp

$(IntermediateDirectory)/Main.cpp$(ObjectSuffix): Main.cpp $(IntermediateDirectory)/Main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/Main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Main.cpp$(DependSuffix): Main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Main.cpp$(DependSuffix) -MM Main.cpp

$(IntermediateDirectory)/Main.cpp$(PreprocessSuffix): Main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Main.cpp$(PreprocessSuffix) Main.cpp

$(IntermediateDirectory)/LightRenderer.cpp$(ObjectSuffix): LightRenderer.cpp $(IntermediateDirectory)/LightRenderer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/LightRenderer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LightRenderer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LightRenderer.cpp$(DependSuffix): LightRenderer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LightRenderer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LightRenderer.cpp$(DependSuffix) -MM LightRenderer.cpp

$(IntermediateDirectory)/LightRenderer.cpp$(PreprocessSuffix): LightRenderer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LightRenderer.cpp$(PreprocessSuffix) LightRenderer.cpp

$(IntermediateDirectory)/Shader.cpp$(ObjectSuffix): Shader.cpp $(IntermediateDirectory)/Shader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/Shader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Shader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Shader.cpp$(DependSuffix): Shader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Shader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Shader.cpp$(DependSuffix) -MM Shader.cpp

$(IntermediateDirectory)/Shader.cpp$(PreprocessSuffix): Shader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Shader.cpp$(PreprocessSuffix) Shader.cpp

$(IntermediateDirectory)/glad.c$(ObjectSuffix): glad.c $(IntermediateDirectory)/glad.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/glad.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/glad.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/glad.c$(DependSuffix): glad.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/glad.c$(ObjectSuffix) -MF$(IntermediateDirectory)/glad.c$(DependSuffix) -MM glad.c

$(IntermediateDirectory)/glad.c$(PreprocessSuffix): glad.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/glad.c$(PreprocessSuffix) glad.c

$(IntermediateDirectory)/TextureLoader.cpp$(ObjectSuffix): TextureLoader.cpp $(IntermediateDirectory)/TextureLoader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/TextureLoader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TextureLoader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TextureLoader.cpp$(DependSuffix): TextureLoader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TextureLoader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TextureLoader.cpp$(DependSuffix) -MM TextureLoader.cpp

$(IntermediateDirectory)/TextureLoader.cpp$(PreprocessSuffix): TextureLoader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TextureLoader.cpp$(PreprocessSuffix) TextureLoader.cpp

$(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix): Mesh.cpp $(IntermediateDirectory)/Mesh.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/naufal/Dokumen/Projects/TryingToMakeAGame/Mesh.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Mesh.cpp$(DependSuffix): Mesh.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Mesh.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Mesh.cpp$(DependSuffix) -MM Mesh.cpp

$(IntermediateDirectory)/Mesh.cpp$(PreprocessSuffix): Mesh.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Mesh.cpp$(PreprocessSuffix) Mesh.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



import json

__DEPRES_DEPENDENCY_DIRECTORY__ = "dependencies"
__DEPRES_CONFIG_FILE__ = ".dep"

"""
This module handles dependency resolution.
"""

class Dependency:
    """
    Defines a dependency that must be acquired to build the project.
    """
    def __init__(self, json):
        self._type = json["type"]
        self._source = json["source"]
        self._name = json["name"]
        self._package = json["package"]
        self._path = json["path"]
        self._files = json["files"]

    def name(self):
        """
        Gets the name of the dependency.
        """
        return self._name

    def type(self):
        """
        Gets the type of the dependency.
        """
        return self._type

    def source(self):
        """
        Gets the source type of the dependency.
        """
        return self._source

    def package(self):
        """
        Gets the name of the package of the dependency.
        """
        return self._package

    def path(self):
        """
        Gets the path to the dependency.
        """
        return self._path

    def retrieve(self):
        """
        Gets a copy of the dependency.
        """
        pass

    def build(self):
        """
        Builds the dependency.
        This should only be called on source dependencies.
        """

    def resolve(self):
        """
        Resolves the dependency.
        """
        pass


class GitDependency(Dependency):
    """
    Defines a git repository dependency.
    """
    def __init__(self, json):
        Dependency.__init__(self, json)


def init(config):
    """
    Initializes an instance of the dependency resolver using the given options.
    :param config: The project configuration options.
    :return: An instance of the dependency resolver.
    """


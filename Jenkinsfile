pipeline {
    agent any

    stages {
        stage('basics') {
            steps {
                sh """
                    cd basics
                    find -type f \( -name 'GNUmakefile' -o -name 'makefile' -o -name 'Makefile' \) -exec bash -c 'cd "$(dirname "{}")" && make' \;
                """
            }
        stage('algos') {
            steps {
                sh """
                    cd basics
                    find -type f \( -name 'GNUmakefile' -o -name 'makefile' -o -name 'Makefile' \) -exec bash -c 'cd "$(dirname "{}")" && make' \;
                """
            }
        }        
    }
}
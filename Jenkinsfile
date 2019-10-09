pipeline {
    agent any

    stages {
        stage('basics') {
            steps {
                sh """
                    ./build.sh
                """
            }
        }
        stage('clean') {
            steps {
                echo "nothing to do."
            }
        }        
    }
}
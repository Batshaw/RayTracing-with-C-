#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"

#include <glm/vec3.hpp>
#include <memory>

class Box : public Shape{
    public:
        // Konstruktor
        Box();
        Box(glm::vec3 const& min, glm::vec3 const& max);
        /*Box(glm::vec3 const min, glm::vec3 const& max, std::string const& name);
        Box(glm::vec3 const& min, glm::vec3 const& max, Color const& color);*/
        Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, std::shared_ptr<Material> const& material);
        ~Box();

        // Methode
        float area() const override;
        float volumen() const override;
        glm::vec3 getMax() const;
        glm::vec3 getMin() const;
        // std::string getName() const override;
        // Color getColor() const override;
        bool is_inBox(glm::vec3 const& punkt);
        bool intersect(Ray const& r, float& t) override;
        Hit intersectHit(Ray const& ray) override;

        std::ostream& print(std::ostream& os) const override;

    private:
        glm::vec3 min_;
        glm::vec3 max_;

};

std::ostream& operator<<(std::ostream& os, Box const& b);


#endif  //BOX_HPP